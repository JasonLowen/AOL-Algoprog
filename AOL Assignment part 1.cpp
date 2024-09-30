#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char loc1[5000][100];
char loc2[5000][100];
int price[5000];
int room[5000];
int bathrooms[5000];
int carparks[5000];
char type[5000][100];
int area[5000];
char furnish[5000][100];
char string1[100];
char string2[100];
char string3[100];
char string4[100];
char string5[100];
char string6[100];
char string7[100];
char string8[100];
char string9[100];
char input[100];
int n = 0;

void readfile(){
	FILE *baca = fopen("file.csv", "r");
	if(baca == NULL){
		perror("Encountering error opening the file ");
		exit(1);
	}
	fscanf(baca, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", string1, string2, string3, string4, string5, string6, string7, string8, string9);
	while(!feof(baca)){
		fscanf(baca, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", &loc1[n], &loc2[n], &price[n], &room[n], &bathrooms[n], &carparks[n], &type[n], &area[n], &furnish[n]);
		n++;
	}
	fclose(baca);	
}

void menu1(char loc1[][100], int n){
	int counter[5000] = {0};
	for(int i = 0; i < n; i++){
		counter[i] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(counter[i] != 0){
				if(strcmp(loc1[i], loc1[j]) == 0){
					counter[i]++;
					counter[j] = 0;
				}
			}
		}
	}
	int biggest = counter[0];
	int smallest = counter[0];
	int markbig = 0;
	int marksmall = 0;
	for(int i = 0; i < n; i++){
		if(counter[i] != 0){
			printf("%s : %d\n", loc1[i], counter[i]);
			if(counter[i] >= biggest){
				biggest = counter[i];
				markbig = i;
			}
			if(counter[i] <= smallest){
				smallest = counter[i];
				marksmall = i;
			}
		}
	}
	printf("Maximum value: %s with frequency: %d\n", loc1[markbig], biggest);
	printf("Minimum value: %s with frequency: %d\n", loc1[marksmall], smallest);
}

void menu2(int price[], int n){
	int smallest = price[0];
	int biggest = price[0];
	double total = 0;
	for(int i = 0; i < n; i++){
		if(price[i] >= biggest){
			biggest = price[i];
		}
		if(price[i] <= smallest){
			smallest = price[i];
		}
		total += price[i];
	}
	double average = total / n;
	printf("Minimum value = %d\n", smallest);
	printf("Maximum value = %d\n", biggest);
	printf("Average value = %.2lf\n", average);
}

void menu3(int room[], int n, int p){
	int counter[5000] = {0};
	for(int i = 0; i < n; i++){
		counter[i] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(counter[i] != 0){
				if(room[i] == room[j]){
					counter[i]++;
					counter[j] = 0;
				}
			}
		}
	}
	int biggest = counter[0];
	int smallest = counter[0];
	int markbig = 0;
	int marksmall = 0;
	for(int i = 0; i < n; i++){
		if(counter[i] != 0){
			if(p == 1){
				printf("Frequency of place with %d rooms : %d\n", room[i], counter[i]);
			}
			else if(p == 2){
				printf("Frequency of place with %d bathrooms : %d\n", room[i], counter[i]);
			}
			else if(p == 3){
				printf("Frequency of place with %d carparks : %d\n", room[i], counter[i]);
			}
			if(counter[i] >= biggest){
				biggest = counter[i];
				markbig = i;
			}
			if(counter[i] <= smallest){
				smallest = counter[i];
				marksmall = i;
			}
		}
	}
	
	printf("Maximum value: %d with frequency: %d\n", room[markbig], biggest);
	printf("Minimum value: %d with frequency: %d\n", room[marksmall], smallest);
}

int main(){
	
	readfile();
	printf("Options : loc1, loc2, price, room, bathrooms, carparks, type, area, furnish\n");
	printf("Please input the name of the column you want to describe :\n");
	scanf("%[^\n]", input); getchar();
	if(strcmp(input, "loc1") == 0){
		menu1(loc1, n);
	}
	else if(strcmp(input, "loc2") == 0){
		menu1(loc2, n);
	}
	else if(strcmp(input, "price") == 0){
		menu2(price, n);
	}
	else if(strcmp(input, "room") == 0){
		menu3(room, n, 1);
	}
	else if(strcmp(input, "bathrooms") == 0){
		menu3(bathrooms, n, 2);
	}
	else if(strcmp(input, "carparks") == 0){
		menu3(carparks, n, 3);
	}
	else if(strcmp(input, "type") == 0){
		menu1(type, n);
	}
	else if(strcmp(input, "area") == 0){
		menu2(area, n);
	}
	else if(strcmp(input, "furnish") == 0){
		menu1(furnish, n);
	}
	else{
		printf("Category not found!\n");
	}
		
	return 0;
}
