#include <iostream>

using namespace std;

void main()
{
	// 2. �̹��������� ���� ��������� ���� (��ü ������ ũ�⸸ŭ �ҷ��鿩 �ٸ����Ͽ� ����)
	FILE* Image_File = nullptr;
	FILE* Image_Copy_File = nullptr;

	char readImage = 0;
	int Count = 0;

	errno_t err = fopen_s(&Image_File, "./Data/Image.jpg", "rb");
	errno_t errcpy = fopen_s(&Image_Copy_File, "./Data/ImageCopy.jpg", "wb");

	if (0 == err && 0 == errcpy)
	{
		cout << "�̹��� ���� �ҷ����� ����" << endl;

		while(!feof(Image_File))
		{
			fread(&readImage, 1, 1, Image_File);
			fwrite(&readImage, 1, 1, Image_Copy_File);
		}

		fclose(Image_File);
		fclose(Image_Copy_File);
	}
	else
	{
		cout << "�̹��� ���� �ҷ����� ����" << endl;
	}
}