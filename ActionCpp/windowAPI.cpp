#include "windowAPI.h"

void windowAPI::saveFile()
{
	// 创建文件句柄
	HANDLE file_handle = CreateFileA(
		file_name.c_str(),
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_FLAG_NO_BUFFERING | FILE_FLAG_WRITE_THROUGH,
		NULL);

	if (file_handle == INVALID_HANDLE_VALUE) {
		std::cout << "打开文件失败" << std::endl;
		return;
	}

	// 写入旧参数测试
	int new_size = sizeof(params);
	int origin_size = sizeof(params);
	int len = 4096 - (origin_size % 4096) + origin_size;
	// 对其到4096，因为使用了FILE_FLAG_NO_BUFFERING
	uchar* dst = new uchar[len];
	memset(dst, 0, len);// len会比origin_size多一些长度
	memcpy(dst, params, origin_size);

	DWORD dw_written(0);
	BOOL ret = WriteFile(file_handle, dst, len, &dw_written, NULL);
	delete[] dst;

	DWORD err = GetLastError();
	CloseHandle(file_handle);

	if (!ret) {
		std::cout << "保存文件失败:"  << std::endl;
		return;
	}
	else {
		std::cout << "保存文件成功" << std::endl;
	}
	return;

}

void windowAPI::restoreFile()
{
	int restore_data_size = sizeof(params_restore);
	int old_data_size = sizeof(params_old);
	int len = 4096 - (old_data_size % 4096) + old_data_size;

	HANDLE file_handle = CreateFileA(
		file_name.c_str(),
		GENERIC_READ,
		NULL,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_READONLY,
		NULL);

	if (file_handle == INVALID_HANDLE_VALUE) {
		std::cout << "打开文件失败" << std::endl;
		return;
	}

	DWORD file_size = GetFileSize(file_handle, NULL), zero_value = 0;
	char * buffer, *temp_buffer;
	buffer = (char *)malloc(file_size);
	temp_buffer = buffer;
	ZeroMemory(buffer, file_size);
	DWORD dw_bytes_to_read = file_size;
	LPDWORD dw_bytes_read = &zero_value;
	BOOL ret = ReadFile(file_handle, temp_buffer, dw_bytes_to_read, dw_bytes_read, NULL);

	if (len >= file_size) {
		std::cout << "加载旧参数，需要升级" << std::endl;
		ParamStrOld *old = (ParamStrOld*)malloc(old_data_size);
		memcpy(old, temp_buffer, std::min(old_data_size, int(file_size)));
		for (int i = 0; i < 100; i++) {
			memcpy(&params_restore[i], &old[i], sizeof(ParamStrOld));
		}

	}
	else {
		std::cout << "加载当前类型参数" << std::endl;
		memcpy(&params_restore, temp_buffer, std::min(restore_data_size, int(file_size)));
	}

	
	CloseHandle(file_handle);
}

void windowAPI::prepare()
{
	// 随意修改一些东西，查看变化
	params[0].p_int_1 = 1;
	params[0].p_float_1 = 3.4;
	memcpy(params[0].p_char_6, "gggggggggggggggg", sizeof(params[0].p_char_2));

	params_old[0].p_int_1 = 1;
	params_old[0].p_float_1 = 3.4;
}

void windowAPI::exec()
{
	prepare();
	//saveFile();
	restoreFile();
}
