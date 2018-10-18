#include "CarModel.h"
#include "BenzModel.h"
#include "BMWModel.h"
#include "BenzBuilder.h"
#include "BMWBuilder.h"
#include "Director.h"

void DoBenzRun()//û��ʹ��ģʽʱ����Ҫ�Ѳ���һ��һ���Ĵ���ģ�͡�
{
	cout << "----------���ɱ���ģ��----------" << endl;
	CBenzModel *pBenz = new CBenzModel();
	vector<string> seq;
	seq.push_back("engine boom");//�ͻ�Ҫ��run��ʱ���ȷ�������
	seq.push_back("start");//��������
	seq.push_back("stop");//����һ�ξ�ͣ����

	pBenz->SetSequence(&seq);
	pBenz->Run();
	delete pBenz;
}

//ʹ��ģʽ����benzBuilder��bmwBuilder�����ɣ�����ʹ��ͬ���Ĵ���˳��
void DoBuilder()
{
	cout << "----------��ͬһ��˳������ģ��----------" << endl;
	vector<string> seq;
	seq.push_back("engine boom");
	seq.push_back("start");
	seq.push_back("stop");

	CBenzBuilder benzBuilder;
	benzBuilder.SetSequence(&seq);
	CBenzModel *pBenz = dynamic_cast<CBenzModel*>(benzBuilder.GetCarModel());
	pBenz->Run();//���ø���ķ���

	CBMWBuilder bmwBuilder;
	bmwBuilder.SetSequence(&seq);
	CBMWModel *pBmw = dynamic_cast<CBMWModel*>(bmwBuilder.GetCarModel());
	pBmw->Run();
}
void DoDirector()//ʹ��ָ��������װ�������߼����Ѵ�����˳���ھ���ָ���������档
{
	cout << "----------��������ģ��----------" << endl;
	CDirector director;

	//1W��A���͵ı��۳�
	cout << "----------1W��A���͵ı��۳�----------" << endl;
	for (int i = 0; i < 2; i++)
		director.GetABenzModel()->Run();

	//100W��B���͵ı��۳�
	cout << "----------100W��B���͵ı��۳�----------" << endl;
	for (int i = 0; i < 2; i++)
		director.GetBBenzModel()->Run();

	//1000W��C���͵ı�����
	cout << "----------1000W��C���͵ı�����----------" << endl;
	for (int i = 0; i < 2; i++)
		director.GetCBMWModel()->Run();
}
int main()
{
	DoBenzRun();

	DoBuilder();

	DoDirector();

	system("pause");
	return 0;
}