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
	}
	fscanf(baca, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", string1, string2, string3, string4, string5, string6, string7, string8, string9);
	while(!feof(baca)){
		fscanf(baca, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", &loc1[n], &loc2[n], &price[n], &room[n], &bathrooms[n], &carparks[n], &type[n], &area[n], &furnish[n]);
		n++;
	}
	fclose(baca);	
}

void sorting(char loc1[][100], char loc2[][100], int price[], int room[], int bathrooms[], int carparks[], char type[][100], int area[], char furnish[][100], int n){
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(strcmp(loc1[i], loc1[j]) > 0){
				char temp[100];
				strcpy(temp, loc1[i]);
				strcpy(loc1[i], loc1[j]);
				strcpy(loc1[j], temp);
				strcpy(temp, loc2[i]);
				strcpy(loc2[i], loc2[j]);
				strcpy(loc2[j], temp);
				int temp1;
				temp1 = price[i];
				price[i] = price[j];
				price[j] = temp1;
				temp1 = room[i];
				room[i] = room[j];
				room[j] = temp1;
				temp1 = bathrooms[i];
				bathrooms[i] = bathrooms[j];
				bathrooms[j] = temp1;
				temp1 = carparks[i];
				carparks[i] = carparks[j];
				carparks[j] = temp1;
				strcpy(temp, type[i]);
				strcpy(type[i], type[j]);
				strcpy(type[j], temp);
				temp1 = area[i];
				area[i] = area[j];
				area[j] = temp1;
				strcpy(temp, furnish[i]);
				strcpy(furnish[i], furnish[j]);
				strcpy(furnish[j], temp);
			}
		}
	}
}

int main(){
	
	readfile();
	sorting(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, n);
	printf("%-30s | %-15s | %-8s | %-7s | %-10s | %-10s | %-10s | %-5s | %-5s\n", "Location 1", "Location 2", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Area", "Furnish");
	for(int i = 0; i < n; i++){
		printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
	}
	
	return 0;
}
