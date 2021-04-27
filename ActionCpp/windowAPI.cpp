#include "windowAPI.h"

void windowAPI::saveFile()
{
	// �����ļ����
	HANDLE file_handle = CreateFileA(
		file_name.c_str(),
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_FLAG_NO_BUFFERING | FILE_FLAG_WRITE_THROUGH,
		NULL);

	if (file_handle == INVALID_HANDLE_VALUE) {
		std::cout << "���ļ�ʧ��" << std::endl;
		return;
	}

	// д��ɲ�������
	int new_size = sizeof(params);
	int origin_size = sizeof(params);
	int len = 4096 - (origin_size % 4096) + origin_size;
	// ���䵽4096����Ϊʹ����FILE_FLAG_NO_BUFFERING
	uchar* dst = new uchar[len];
	memset(dst, 0, len);// len���origin_size��һЩ����
	memcpy(dst, params, origin_size);

	DWORD dw_written(0);
	BOOL ret = WriteFile(file_handle, dst, len, &dw_written, NULL);
	delete[] dst;

	DWORD err = GetLastError();
	CloseHandle(file_handle);

	if (!ret) {
		std::cout << "�����ļ�ʧ��:"  << std::endl;
		return;
	}
	else {
		std::cout << "�����ļ��ɹ�" << std::endl;
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
		std::cout << "���ļ�ʧ��" << std::endl;
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
		std::cout << "���ؾɲ�������Ҫ����" << std::endl;
		ParamStrOld *old = (ParamStrOld*)malloc(old_data_size);
		memcpy(old, temp_buffer, std::min(old_data_size, int(file_size)));
		for (int i = 0; i < 100; i++) {
			memcpy(&params_restore[i], &old[i], sizeof(ParamStrOld));
		}

	}
	else {
		std::cout << "���ص�ǰ���Ͳ���" << std::endl;
		memcpy(&params_restore, temp_buffer, std::min(restore_data_size, int(file_size)));
	}

	
	CloseHandle(file_handle);
}

void windowAPI::prepare()
{
	// �����޸�һЩ�������鿴�仯
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
