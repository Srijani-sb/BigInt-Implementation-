#include<stdio.h>
#include<string.h>
void Add(char arr1[],char arr2[])
{
	char result[32]; // 1024 bits==>32 characters
	int carry,answer=0,len1=strlen(arr1)-1,len2=strlen(arr2)-1;
	int size_result=0,temp;
	int i,j;
	if(len2>len1){
		size_result=len2+1;
	}
	else{
		size_result=len1+1;
	}
	for(i=0;i<32;i++){   // intialize the character array to 0
		result[i]='0';
	}
	temp=size_result;
	while(len1>=0 && len2>=0)
	{
		answer=(arr1[len1]-'0')+(arr2[len2]-'0')+carry; //integer
		if(answer>=10){
			carry=answer/10;
			answer=answer%10;
			result[size_result]=answer+'0';
		}
		else{
			carry=0;
			result[size_result]=answer+'0';
		}
		len1--;len2--;size_result--; //iterates from last to first and moves to next digit
	}
	while(len1>=0)
	{
		answer=(arr1[len1]-'0')+carry;
		if(answer>=10){
			carry=answer/10;
			answer=answer%10;
			result[size_result]=answer+'0';
		}
		else{
			carry=0;
			result[size_result]=answer+'0';
		}
		len1--,size_result--;
	}
	while(len2>=0)
	{
		answer=(arr2[len2]-'0')+carry;
		if(answer>=10){
			carry=answer/10;
			answer=answer%10;
			result[size_result]=answer+'0';
		}
		else{
			carry=0; // if this is not mentioned then it would take the previous carry generated 
			result[size_result]=answer+'0';
		}
		len2--,size_result--; // moving from back to front in digits
	}
	if(carry==1)
	{
		result[0]+=1; // add last element to 1 which is already a character
	}
	printf("\nAddition\n");
	for(i=0;i<temp+1;i++){
		printf("%c ",result[i]);
	}
	printf("\n");
}
int big(char n1[], char n2[]){
	int i=0, j=0; //if flag == 1 => A1[] is bigger, flag == 2 => A2[] is bigger
	int len1 = strlen(n1), len2 = strlen(n2);
	if(len1 > len2){
		return 1;
	}
	else if(len2 > len1){
		return 2;
	}
	else{
		while(i<len1 && j<len2){
			if(n1[i] > n2[j]){
				return 1;
			}
			else if(n1[i] < n2[j]){
				return 2;
			}
			else{
				i++,j++;
			}
		}
	}
	return 0; // they're equal
}
void Sub(char n1[], char n2[]){
	char ans[32];
	int integer=0, len2= strlen(n2)-1, len1= strlen(n1)-1, ans_len=0,i,j;
	if(len2>len1){
		ans_len = len2+1;
	}
	else{
		ans_len = len1+1;
	}
	for(i=0; i<ans_len; i++){
		ans[i] = '0';
	}
	int copy = ans_len + 1;
	int num = big(n1, n2);
	while(len1 >= 0 && len2 >= 0){
		if(num == 1 || num == 0){
			if(n1[len1] >= n2[len2]){
				integer = (n1[len1] - 48) - (n2[len2] - 48);
				ans[ans_len] = integer + 48;
			}
			else{
				n1[len1-1]--;
				n1[len1] += 10;
				ans[ans_len] = (n1[len1] - 48) - (n2[len2] - 48) + 48;
			}
		}
		else if(num == 2){
			if(n2[len2] >= n1[len1]){
				integer = (n2[len2] - 48) - (n1[len1] - 48);
				ans[ans_len] = integer + 48;
			}
			else{
				n2[len2-1]--;
				n2[len2] += 10;
				ans[ans_len] = (n2[len2] - 48) - (n1[len1] - 48) + 48;
			}
		}
		len1--; len2--; ans_len--;
	}
	while(len1 >= 0){
		ans[ans_len] = (n1[len1]);
		len1--; ans_len--;
	}
	while(len2 >= 0){
		ans[ans_len] = (n2[len2]);	
		len2--; ans_len--;
	}
	if(num==2)
	{
		ans[0]='-';
	}
	else
	{
		ans[0]='+';
	}
	printf("\nSubtracting\n");
	for(i=0; i<copy; i++){
		printf("%c ", ans[i]);
	}
	printf("\n");
}
void Multiply(char n1[], char n2[]){
	int len1 = strlen(n1), len2 = strlen(n2), size=len1+len2, flag = 0, carry = 0,i,j;
	char ans[size];
	for(i=0; i<size; i++){
		ans[i] = '0';
	}
	for(i=len1-1 ;i>=0 ;i--)
	{
		for(j=len2-1; j>=0; j--)     // build the number by multiplying one digit at the time
		{
			flag = ((n1[i]-'0') * (n2[j]-'0')) + (ans[i+j+1]-'0');
			if(flag >= 10){
				carry = flag/10;
				ans[i+j+1] = flag%10 + 48;
				ans[i+j] += carry;
			}
			else{
				carry = 0;
				ans[i+j+1] = flag + 48;
			}
		}
		
	}
	printf("\nMultilplication\n");
	for(i=0; i<size; i++){
		printf("%c ", ans[i]);
	}
	printf("\n");
}
int main()
{
	char str1[32],str2[32];
	int i;
	for(i=0; i<32; i++){
		str1[i] = '0';
	}
	for(i=0; i<32; i++){
		str2[i] = '0';
	}
	printf("Enter 1st number:");
	scanf("%s",str1);
	printf("Enter 2nd number:");
	scanf("%s",str2);
	
	Add(str1,str2);
	Sub(str1,str2);
	Multiply(str1,str2);
	
	
}
