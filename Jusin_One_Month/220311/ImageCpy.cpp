#include <iostream>

using namespace std;

void main()
{
	// 2. �̹��������� ���� ��������� ���� (��ü ������ ũ�⸸ŭ �ҷ��鿩 �ٸ����Ͽ� ����)
	FILE* Image_File = nullptr;
	FILE* Image_Copy_File = nullptr;

	char* readImage = "";
	int Count = 0;

	errno_t err = fopen_s(&Image_File, "./Data/Image.jpg", "rb");
	errno_t errcpy = fopen_s(&Image_File, "./Data/ImageCopy.jpg", "wb");

	if (0 == err && 0 == errcpy)
	{
		cout << "�̹��� ���� �ҷ����� ����" << endl;

		while(!feof(Image_File))
		{
			fwrite(Image_Copy_File, 1, 1,ftell(Image_File));

			fseek(Image_File, 1, SEEK_SET);

		}

		fclose(Image_File);
		fclose(Image_Copy_File);
	}
	else
	{
		cout << "�̹��� ���� �ҷ����� ����" << endl;
	}
}