#include "HttpRequest.h"
#include <windows.h>
#include <stdio.h>
#include <wininet.h>
#include <string>
#pragma comment(lib, "wininet.lib")

HttpRequest::HttpRequest()
{
}

HttpRequest::~HttpRequest()
{
}

/* ========================================================================= */
/* �֐���: requestMessage													 */
/* ���e: �w��URL��HTML�\�[�X���擾����										 */
/* ���l:		requestURL:�w��URL												 */
/*			htmlSource:�擾HTML�\�[�X�̊i�[��									 */
/* ========================================================================= */
void HttpRequest::requestMessage(const std:: string &requestURL, std::string &htmlSource)
{
	const std::string agent = "peerst";

	// ���C�u����������.
	HINTERNET handleNet = NULL;
	handleNet = InternetOpen(agent.c_str(), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (NULL == handleNet)
	{
		return;
	}

	// URL���J��.
	HINTERNET handleURL = NULL;
	handleURL = InternetOpenUrl(handleNet, requestURL.c_str(), NULL, 0, 0, 0);
	if (NULL == handleURL)
	{
		return;
	}

	// �{�f�B���b�Z�[�W�ǂݍ���.
	DWORD readSize = 0;
	const LONG bufferSize = 32;
	char str[bufferSize] = {};

	while (true)
	{
		BOOL ret = false;
		ret = InternetReadFile(handleURL, str, sizeof(str), &readSize);
		str[bufferSize - 1] = '\0';

		// �G���[ or �Ō�܂œǂݍ��݂ł����玟�̏�����.
		if ((FALSE == ret) || (0 == readSize))
		{
			break;
		}

		// ��M�f�[�^��ǋL.
		htmlSource += str;
	}

	// TODO �G���R�[�h�ϊ��N���X���쐬����.
	// TODO �����G���R�[�h���w�b�_����擾���A�w��̕����R�[�h�փG���R�[�h�H
	
	//	int ret = WideCharToMultiByte( CP_ACP, 0, str, -1, NULL, 0, NULL, NULL );

	//printf("%s", str);

	/*
	char *message = NULL;

	while (true)
	{
		if (!HttpQueryInfo(handleURL, HTTP_QUERY_RAW_HEADERS_CRLF, message, &size, NULL))
		{
			// �i�[�惁�����m��.
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				message = new char[size];
				continue;
			}
			else
			{
				return;
			}
		}
		break; 
	}
	*/

//	printf("%s", message);

	InternetCloseHandle(handleURL);
	InternetCloseHandle(handleNet);
}
