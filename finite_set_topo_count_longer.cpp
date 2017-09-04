#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

bool isTopo(uint64_t * subset_S, uint64_t len, uint64_t len_S_1); 

int main()
{
	uint64_t i, j, k, len;
	uint64_t len_X = 0;
	printf("������һ��С��32��������\n");
	scanf("%ld", &len_X);
        printf("\n");

	// ��װ���ɼ���X���ݼ�S 
	uint64_t len_S = 1;
	for(i = 0;i<len_X;i++) len_S <<= 1;
	uint64_t len_S_2 = len_S - 2; 
	uint64_t len_S_supplement = len_S;
	for(;i<len_S_2;i++) len_S_supplement <<= 1;
	len_S_supplement -= 1;


	// һ��������S���Ӽ�, �����Ƿ���X������
	uint64_t count = 2;
	uint64_t *subset_S = new uint64_t[len_S_2]; // ##--
	for(i = 1;i<len_S_supplement;i++) 	// i=0��ʾ���������Ӽ�, ����ƽ������ 
	{									// i=len_S_supplement������ɢ���� 
		// ����subset_S 
		j = 1;
		k = 1; // kΪ1����Ϊ0Ϊ�ռ�, ����ѡ�� 
		len = 0;
		while(j <= i)
		{
			if((j&i) != 0)
				subset_S[len++] = k;
			j <<= 1;
			k++;
		}
		// ��֤subset_S�Ƿ�ΪX������
		if(isTopo(subset_S, len, len_S - 1)) 
		{
		    count++;
		    if(count%100 == 0) printf("%ld, %ld, %ld\n", count, i, len_S_supplement);
		}
	}
	printf("%ld\n", count);
	return 0;
}

bool isTopo(uint64_t * subset_S, uint64_t len, uint64_t len_S_1)
{
	uint64_t i, j, k, inter, uni;
	for(i=0;i<len-1;i++)
		for(j=i+1;j<len;j++)
		{
			inter = subset_S[i] & subset_S[j];
			uni = subset_S[i] | subset_S[j];
			
			k = 0;
			while(k < len && inter != subset_S[k]) k++;
			if(k == len && inter != 0) return false;
			
			k = 0;
			while(k < len && uni != subset_S[k]) k++;
			if(k == len && uni != len_S_1) return false;
		}
	return true;
}





