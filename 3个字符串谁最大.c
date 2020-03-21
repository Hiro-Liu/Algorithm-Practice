#include <stdio.h>
#include <string>

int main()
{
	int const N = 100;
	char s1[N], s2[N], s3[N];
	gets_s(s1);
	gets_s(s2);
	gets_s(s3);
  
	if (strcmp(s1, s2) >= 0){
		if (strcmp(s1, s3) >= 0)
			puts(s1);
		else
			puts(s3);
	}
	else{
		if (strcmp(s2, s3) >= 0)
			puts(s2);
		else
			puts(s3);
	}
  
	return 0;
}
