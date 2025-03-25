#include <stdio.h>

void disp(char s[]){
	int i = 0;
	while(s[i] != '\0'){
		printf("%c", s[i]);
		i++;
	}
	printf("\n");
}

int len(char s[]){
	int i = 0;
	while(s[i] != '\0'){
		i++;
	}
	return(i);
}

void rev(char s[]){
	for(int i = len(s); i >= 0; i--){
		printf("%c", s[i]);
	}
	printf("\n");
}

void equal(char s[], char s2[]){
	if(len(s) != len(s2)){
		printf("Not Equal\n");
	}
	else{
		int broke = 0;
		for(int i = 0; i < len(s); i++){
			if(s[i] != s2[i]){
				broke = 1;
				printf("Not Equal\n");
				break;
			}
		}
		if(!broke){
			printf("Strings are equal\n");
		}
	}
	
}
void equalCaller(char s[]){
	printf("Enter length of second string\n");
	int l2;
	scanf("%d", &l2);
	char s2[l2+1];
	s2[l2] = '\0';
	for(int i = 0; i < l2; i++){
		printf("enter char at %d\n",i);
		scanf(" %c", &s2[i]);
	}
	equal(s,s2);
}

void palindrome(char s[]){
	printf("reverse of string is ");
	rev(s);
	int j = len(s) - 1;
	int broke = 0;
	
	for(int i = 0; i < j+1; i++){
		if(s[i] != s[j]){
			printf("not a palindrome\n");
			broke = 1;
			break;
		}
		j--;
	}
	
	if(!broke){
		printf("string is a palindrome\n");
	}
}

int main(){
	char yn = 'y';
	while(yn != 'n'){
		printf("Enter length of your string\n");
		int l;
		scanf("%d", &l);
		
		char s[l+1];
		s[l] = '\0';
		for(int i = 0; i < l; i++){
			printf("enter char at %d\n",i);
			scanf(" %c", &s[i]);
		}
		printf("Now performing operations with- ");
		disp(s);
		
		int choice;
		printf("which operation do you want to perform? \n");
		printf("1 for length\n2 for reversal\n3 for equality\n4 for palindrome\n5 for substring check\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
			printf("length of string is %d\n", len(s));
			break;
			
			case 2:
			printf("reverse string is ");
			rev(s);
			break;
			
			case 3:
			equalCaller(s);
			break;
			
			case 4:
			palindrome(s);
			
			break;
			
		}
		
		printf("\nperform another operation? y/n\n");
		scanf(" %c", &yn);
	}
	return 0;
}
