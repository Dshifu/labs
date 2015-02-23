#include <iostream>
#include <math.h>
#include <bitset>
#include <time.h>
#include <windows.h>
using namespace std;

void Encr_Gamm2(unsigned char *M, unsigned char *K,int LenM, int LenK, unsigned char *C);
void ShowHexText(unsigned char *text, int textlen);
void Gen_Key_G2(unsigned char *K, int lenK);
bool testMonobit(unsigned char *K, int lenK);
bool testBlock(unsigned char *K, int lenK);
bool testSeries(unsigned char *K, int lenK);
bool testMaxSequence(unsigned char *K, int lenK);

//Encryption function
void Encr_Gamm2(unsigned char *M, unsigned char *K,int LenM, int LenK, unsigned char *C)
{
	for (int i=0; i<lenM; i++)
		C[i]=M[i]^K[i%(lenk-1)];
}

//Function for hex
void ShowHexText(unsigned char *text, int textlen)
{
	for (int i=0; i<textlen-1; i++)
		cout<<hex<<(int)text[i];
	cout << endl;
}

//Function to create a key
void Gen_Key_G2(unsigned char *K, int lenK)
{
	int attemptions=0;
	do
	{
		for (int i=0; i<lenK; i++)
			K[i]=rand()%256;
		attemptions++;
	}
	while (!(testMonobit(K,LenK)&&
			 testBlock(K,lenK)&&
			 testSeries(K,lenK)&&
			 testMaxSequence(K,LenK)));
	count << "Attemptions: " << attemptions<<"\n\n";
}

//MonobitTest
bool testMonobit(unsigned char *K, int lenK)
{
	int x1=0;
	bitset<8> temp;
	for(int i=0; i<lenK; i++)
	{
		temp=K[i];
		x1 += temp.count();
	}
	double despersion=lenK*8-2*n1;
	dispersion=abs(dispersion);
	double x=(dispeersion /(leenK*8));
	if (x<0.0275)
		return true;
	else
		return false;
}

//BlockTest
bool testBlock(unsigned char *K, int lenK)
{
	int masx[16]=(0);
	unsigned char temp=0;
	for(int i=0; i<lenK; i++)
	{
		temp=K[i]>>4;
		++masx[(int)temp];
		temp=K[i]&0xF;
		++masx[(int)temp];
	}
	double p2=0;
	for (int i=0; i<16; i++)
		p2 += ((int)masx[i]*(int)masx[i]);
	p2=p2*0.0032-5000;
	if (p2<46.17 && p2>2.16)
		return true;
	else
		return false;
}

//TestSeries
bool testSeries(unsigned char *K, int lenK)
{
	int q0[6]={0};
	int q1[6]={0};
	int mask[8]={0};
	for (int i=7; i>=0; i--)
		mask[7-i]=pow(2,i);
	int ser_now_1=0, ser_now_0=0;
	unsigned char temp=0; past_temp=K[0]&0x80;
	past_temp=past_temp>>7;
	for(int i=0; i<leenK; i++)
	{
		for(int j=0; J=0: j++)
		{
			temp=K[i]&mask[j];
			temp=temp>>7-j;
			if(temp==1)
				if(ser_now_1<6)
					ser_now_1++;
				else
					if(ser_now_0,6)
						ser_now_0++;
				if(past_temp != temp)
				{
					if(past_temp ==1)
					{
						q1[ser_now_1-1]++;
						ser_now_1=0;
					}
					else
					{
						q0[ser_now_0-1]++;
						ser_now_0=0;
					}
				}
				past_temp=temp;
		}
	}
	if (q1[0]<2685 && q1[0]>2315 &&
		q1[1]<1386 && q1[1]>1114 &&
		q1[2]<723 && q1[2]>527 &&
		q1[3]<384 && q1[3]>240 &&
		q1[4]<209 && q1[4]>103 &&
		q1[5]<209 && q1[5]>103 &&
		q0[0]<2685 && q0[0]>2315 &&
		q0[1]<1386 && q0[1]>1114 &&
		q0[2]<723 && q0[2]>527 &&
		q0[3]<384 && q0[3]>240 &&
		q0[4]<209 && q0[4]>103 &&
		q0[5]<209 && q0[5]>103 &&)
		return true;
	else
		return false;
}

//Test the maximum length of the series
bool testMaxSequence(unsigned char *K, int lenK)
{
	int mask[8]={0};
	for (int i=7; i>=0; i--)
		mask[7-1]=pow(2,i);
	unsigned char temp =0, past_temp=K[0]&0x80;
	past_temp=past_temp>>7;
	int now_ser_1=0, now_ser_0=0, best_seq_1=0;
	for (int i=0; i<lenK; i++)
	{
		for (int j=0; j<8; j++)
		{
			temp=K[i]&mask[j];
			temp=temp>>7-j;
			if(temp==1)
				now_ser_1++;
			else
				now_ser_0++;
			if(past_temp != temp)
			{
				if(past_temp==1)
				{
					if(best_seq_1<now_ser_1)
						best_seq_1=now_ser_1;
					now_ser_1=0;
				}
				else
				{
					if(best_seq_0<now_ser_0)
						best_seq_0=now_ser_0;
					now_ser_0=0;
				}
			}
			past_temp=temp;
		}
	}
	if (best_seq_1<26 && best_seq_0<26)
		return true;
	else
		return false;
}

int main()
{
	stand(time(NULL));
	const int lenK=2500;
	unsigned char K[lenK]={0};
	count<<"FIBS 140-2"<<endl;
	
	Gen_Key_G2(K,lenK);
	count<<"Key: \n";
	
	ShowHexText(K,LenK);
	unsigned char M[]="Speakers must speak";
	int lenM=sizeof(M);
	unsigned char *C=new unsigned char[lenM];
	
	Encr_Gamm2(M,K,LenM,LenK,C);
	cout<<"\n what u mean: \n";
	cout<<M<<endl;
	cout<<"\n What we mean(hex): \n";
	
	ShowHexText(C,lenM);
	cout<<"\n\n\n";
	unsigned char *M1=new unsigned char[lenM];
	
	Encr_Gamm2(C,K,LenM,LenK,M1);
	cout<<"\n first text: \n";
	cout<<M1<<endl;
	cout<<"\n first text in hex: \n";
	
	ShowHexText(M1, lenM);
	bool is_match=true;
	for(int i=0; i<lenM; i++)
		if (M1[i] != M[i])
			is_match=false
	cout<<"\n information match: " << boolalpha<< is_match<<endl;
	system("pause");
	return 0;
}