#include <iostream>

using namespace std;

void main()
{
	// 2. 이미지파일을 파일 입출력으로 구현 (전체 파일의 크기만큼 불러들여 다른파일에 저장)
	FILE* Image_File = nullptr;
	FILE* Image_Copy_File = nullptr;

	char readImage = 0;
	int Count = 0;

	errno_t err = fopen_s(&Image_File, "./Data/Image.jpg", "rb");
	errno_t errcpy = fopen_s(&Image_Copy_File, "./Data/ImageCopy.jpg", "wb");

	if (0 == err && 0 == errcpy)
	{
		cout << "이미지 파일 불러오기 성공" << endl;

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
		cout << "이미지 파일 불러오기 실패" << endl;
	}
}