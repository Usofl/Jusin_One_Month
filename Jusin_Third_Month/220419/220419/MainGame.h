#pragma once
class CMainGame
{
public:				// ������, �Ҹ���
	CMainGame();
	~CMainGame();

public:
	void Initialize(void); // �ʱ�ȭ
	void Update(void);	   // �� �����Ӹ��� ���ŵǴ� �����͸� ����� �Լ�
	void Render(void);     // �� �����Ӹ��� ����ϴ� �Լ�
	void Release(void);    // �����Ҵ��� �����͸� �����ϴ� �Լ�

private:
	HDC m_hDC;

};

