#include <stdio.h>
#include <windows.h>
#include "DebugThread.h"
#include "Web/HttpRequest.h"

#include <regex>
#include <iostream>
#include <mbstring.h>
#include <vector>

// �� EUC-JP -> Shift_JIS
void EucToSJis(char *out, char *inp)
{
    WORD  c;

    while (*inp) {
        if ((BYTE)*inp <= 0x7F) {
            // ASCII
            *out++ = (BYTE)*inp++;
        } else {
            if ((BYTE)*inp == 0x8E) {
                // ���p�J�i
                *out++ = (BYTE)*(inp+1) | 0x80;
            } else {
                // ����
                if ((BYTE)*inp == 0x8F) {
                    strcpy(out, "�E");  // �⏕����(Shift_JIS���Ή�)
                    inp++;
                    out += 2;
                } else {
                    c = MAKEWORD((BYTE)*(inp+1) ^ 0x80, (BYTE)*inp ^ 0x80);
                    *out++ = (char)HIBYTE(_mbcjistojms(c));
                    *out++ = (char)LOBYTE(_mbcjistojms(c));
                }
            }
            inp += 2;
        }
    }
    *out = '\0'; // �I�[
}

void main
{
	std::string url = "�������URL";

	Update("http://")
	{
		SetURL();
		// �X�V
	}

	SetURL("http://")
	{
		delete bbsOperation;
		bbsOperation = new BBSOperation("YY")
	}

	BBSOperator *bbs = new BBSOperation("�������");
	bbs->WriteRes();

	delete bbs;

	bbs->WriteRes();

	/*
	// strategy�Ȃ�
	BBS *bbs = FactoryMethod("�������URL")
	bbs->SetStrategy(bbs);
	bbs->writeRes();
	delete bbs;
	
	bbs = FactoryMethod("YY��URL")
	bbs->SetStrategy(bbs);
	bbs->writeRes();
	delete bbs;

	// ���̍l��
	BBSStrategy *bbs = new BBSStrategy(url);
	bbs->writeRes();
	delete bbs;
	*/
}

enum BBS_TYPE
{
	BBS_NONE = 0,
	BBS_YY,
	BBS_JBBS,
	BBS_2ch,
};

class BBSUrlAnalyzer
{
	BBS_TYPE Anlyze(std::string url)
	{
		// ���

		if (url == "�������")
		{
			return BBS_JBBS;
		}
	}
};

class FactoryMethod
{
public:
	BBS* CreateBBS(std::string url)
	{
		// url�����
		if (url == BBS_YY)
		{
			return new YY();
		}
		else if (url == BBS_JBBS)
		{
			return new JBBS();
		}

		// TODO NULL�I�u�W�F�N�g�ɂ�����
		// �Ή��O�f���̏ꍇ�ɁANULL�`�F�b�N���Ȃ��ėǂ��Ȃ�B
		return NULL;
	}
};

class BBSOperator
{
public:
	BBSOperator(std::string url)
	:bbs(NULL)
	{
		FactoryMethod factory;
		bbs = factory.CreateBBS();
	}

	~BBSOperator()
	{
		delete bbs;
	}

	void WriteRes(std::string text, std::string name, std::string mail)
	{
		bbs->writeRes(text, name, mail);
	}

private:
	BBS *bbs;
};

class BBSStrategy
{
public:
	BBSStrategy()
	:server(),
	genre(),
	boardNo(),
	threadNo()
	{
	}
	virtual long getThreadStopNum() = 0;
	void writeRes(std::string text, std::string name, std::string mail);
	void readRes();
	void getThreadList();
	std::string getBoardName();
	std::string getThreadName();
	long getResNum();

private:
	std::string server;
	std::string genre;
	std::string boardNo;
	std::string threadNo;
};

class YyBbs;
class YYBBS : public BBSStrategy
{
public:
	YY()
	{
	}

	long getThreadStopNum()
	{
		return 1001;
	}
};

class JBBS : public BBSStrategy
{
public:
	long getThreadStopNum()
	{
		HttpRequest http;
		std::string htmlSource = "";
		http.requestMessage("http://jbbs.livedoor.jp/bbs/api/setting.cgi/game/45037/1345901480/", htmlSource);
		char *buffer = new char[htmlSource.size() + 1];

		EucToSJis(buffer, const_cast<char*>(htmlSource.c_str()));

		//printf("%s", buffer);

		std::regex re("BBS_THREAD_STOP=(\\d+)");
		std::match_results<const char *> results;

		if (!std::regex_search(buffer, results, re, std::regex_constants::match_default))
		{
			return 1;
		}

		std::string str = results[1].str();
		long stopNum = atoi(str.c_str());

		return stopNum;
	}
};

int main()
{
	BBSStrategy *strategy = new BBSStrategy();

	// ������Ώ�������
	strategy->SetUrl("������΂̃A�h���X");
	stratery->writeRes("�V���[��", "sage", "�������[");


	strategy->SetUrl("YY�̃A�h���X");
	stratery->writeRes("�V���[��", "sage", "�������[");

	/*
	BBS *yy = new YY();
	BBS *jbbs = new JBBS();


	printf("yy : %d", yy->getThreadStopNum());
	printf("jbbs : %d", jbbs->getThreadStopNum());
	
	
	delete yy;
	delete jbbs;
	*/
}



int main2()
{

	// TODO �X���b�h�̏I���������K�v�H.
	HttpRequest *http = new HttpRequest();

	std::string htmlSource = "";

	// HTML�R�[�h�擾���X���b�h���s.
	//http->requestMessage("http://jbbs.livedoor.jp/bbs/rawmode.cgi/game/45037/1286755510/", htmlSource);
	//http->requestMessage("http://yy64.60.kg/hisyou/dat/1349532495.dat", htmlSource);

	http->requestMessage("http://jbbs.livedoor.jp/bbs/api/setting.cgi/game/45037/1345901480/", htmlSource);

	char *buffer = new char[htmlSource.size() + 1];
	
	/*
	char source[1024];

	for (long i = 0; i < 1024; i++)
	{
		source[i] = htmlSource[i];
	}
	source[1024 - 1] = '\0';
	*/

	EucToSJis(buffer, const_cast<char*>(htmlSource.c_str()));

	//printf("%s", buffer);

	std::regex re("BBS_THREAD_STOP=(\\d+)");
	std::match_results<const char *> results;

	if (!std::regex_search(buffer, results, re, std::regex_constants::match_default))
	{
		return 1;
	}

	std::cout << "prefix: " << results.prefix().str() << std::endl;
	std::cout << "suffix: " << results.suffix().str() << std::endl;
	std::cout << "posision: " << results.position() << std::endl;
	std::cout << "str: " << results.str() << std::endl;

	for (long i = 0; i < results.size(); i++)
	{
		std::cout << "str: " << results[i].str() << std::endl;
		//printf("%d : %s\n", i, results[i].str());
	}

	/*
	// �X���b�h�N���X�̊m�F.
	DebugThread *threadA = new DebugThread("threadA");
	DebugThread *threadB = new DebugThread("threadB");
	DebugThread *threadC = new DebugThread("threadC");
	DebugThread *threadD = new DebugThread("threadD");
	DebugThread *threadE = new DebugThread("threadE");

	threadA->start();
	threadB->start();
	threadC->start();
	threadD->start();
	threadE->start();
	*/

	// �X���b�h���s�҂����[�v.
	while (true)
	{
		Sleep(1);
	}
	/*

	delete threadA;
	delete threadB;
	delete threadC;
	delete threadD;
	delete threadE;
	*/

	return 0;
}

class BbsThread;
class Board
{
public:
	void update(std::string server, std::string genre, std::string boardNo, std::string threadNo);
private:
	std::string name;
	std::vector<BbsThread> threadList;
};

class Res;
class BbsThread
{
public:
	BbsThread()
	:title(), res()
	{
	}
private:
	// �X�����ē�.
	// �X������.
	std::string title;
	std::vector<Res> res;
};

class Res
{
private:
	std::string text;
	std::string name;
	std::string mail;
	std::string date;
	std::string id;
};
