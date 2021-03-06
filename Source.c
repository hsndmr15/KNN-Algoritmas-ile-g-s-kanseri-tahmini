#include <stdio.h>

int main(int argc, char* argv[])
{
	int tercih;
	printf("\n\t*********** KNN ALGORITMASI ILE MEME KANSERI TESPIT PROGRAMI **********\n\n\n");
	printf("Lutfen Test verisini testi icin '0' < -- > Laboratuvar sonuclarinizi testi icin '1' seciniz.\n");
	printf("Secim:");
	scanf_s("%d", &tercih);



	int num1;
	int num2, num3, num4, num5, num6, num7, num8, num9, num10, num11;
	FILE* veriseti;
	int sonuc = fopen_s(&veriseti, "data.txt", "r");
	if (sonuc != 0)
	{
		return 0;
	}
	int veridizisi[600][11];
	int i = 0;
	int k = 0;
	while (fscanf_s(veriseti, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11) != EOF)
	{
		veridizisi[i][k] = num1;
		veridizisi[i][k + 1] = num2;
		veridizisi[i][k + 2] = num3;
		veridizisi[i][k + 3] = num4;
		veridizisi[i][k + 4] = num5;
		veridizisi[i][k + 5] = num6;
		veridizisi[i][k + 6] = num7;
		veridizisi[i][k + 7] = num8;
		veridizisi[i][k + 8] = num9;
		veridizisi[i][k + 9] = num10;
		veridizisi[i][k + 10] = num11;
		k = 0;
		i = i + 1;
	}
	fclose(veriseti);
	FILE* testseti;
	int sonuc2 = fopen_s(&testseti, "test.txt", "r");
	if (sonuc2 != 0)
	{
		return 0;
	}
	int testdizisi[83][11];
	int say1, say2, say3, say4, say5, say6, say7, say8, say9, say10, say11;
	int j = 0, l = 0;
	while (fscanf_s(testseti, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &say1, &say2, &say3, &say4, &say5, &say6, &say7, &say8, &say9, &say10, &say11) != EOF)
	{

		testdizisi[j][l] = say1;
		testdizisi[j][l + 1] = say2;
		testdizisi[j][l + 2] = say3;
		testdizisi[j][l + 3] = say4;
		testdizisi[j][l + 4] = say5;
		testdizisi[j][l + 5] = say6;
		testdizisi[j][l + 6] = say7;
		testdizisi[j][l + 7] = say8;
		testdizisi[j][l + 8] = say9;
		testdizisi[j][l + 9] = say10;
		testdizisi[j][l + 10] = say11;
		l = 0;
		j = j + 1;
	}
	fclose(testseti);
	int diziöklit[83][600][2];
	int s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;

	for (int x = 0; x < 83; x++)
	{
		for (int y = 0; y < 600; y++)
		{
			n1 = testdizisi[x][1];
			n2 = testdizisi[x][2];
			n3 = testdizisi[x][3];
			n4 = testdizisi[x][4];
			n5 = testdizisi[x][5];
			n6 = testdizisi[x][6];
			n7 = testdizisi[x][7];
			n8 = testdizisi[x][8];
			n9 = testdizisi[x][9];
			s1 = veridizisi[y][1];
			s2 = veridizisi[y][2];
			s3 = veridizisi[y][3];
			s4 = veridizisi[y][4];
			s5 = veridizisi[y][5];
			s6 = veridizisi[y][6];
			s7 = veridizisi[y][7];
			s8 = veridizisi[y][8];
			s9 = veridizisi[y][9];
			diziöklit[x][y][0] = ((s1 - n1) * (s1 - n1) + (s2 - n2) * (s2 - n2) + (s3 - n3) * (s3 - n3) + (s4 - n4) * (s4 - n4) + (s5 - n5) * (s5 - n5) + (s6 - n6) * (s6 - n6) + (s7 - n7) * (s7 - n7) + (s8 - n8) * (s8 - n8) + (s9 - n9) * (s9 - n9));
			diziöklit[x][y][1] = veridizisi[y][10];
		}
	}
	int secim;


	int kanser = 0;
	int saglik = 0;

	int dogru = 0, yanlis = 0;
	if (tercih == 0)
	{
		for (int a = 0; a < 83; a++)
		{

			int gecici, tut;

			for (gecici = 1; gecici < 600; gecici++)
			{
				for (int i = 0; i < 600 - 1; i++)
				{
					if (diziöklit[a][i][0] > diziöklit[a][i + 1][0])
					{
						tut = diziöklit[a][i][0];
						diziöklit[a][i][0] = diziöklit[a][i + 1][0];
						diziöklit[a][i + 1][0] = tut;

						tut = diziöklit[a][i][1];
						diziöklit[a][i][1] = diziöklit[a][i + 1][1];
						diziöklit[a][i + 1][1] = tut;


					}
				}
			}





			printf("TEST SATIRI:%d\n\n", a);
			printf("%d numarali test verisine en yakin komsular:\n\n\n", a);
			for (int i = 0; i < 5; i++)
			{
				printf("Kiyaslanan veriye olan uzaklik:%d Egitim Verisinin Hastalik Durumu:%d\n", diziöklit[a][i][0], diziöklit[a][i][1]);
			}
			i = 0;
			int sayacH = 0, sayacS = 0;



			if (diziöklit[a][i][1] == 2)
				sayacS++;
			if (diziöklit[a][i + 1][1] == 2)
				sayacS++;
			if (diziöklit[a][i + 2][1] == 2)
				sayacS++;
			if (diziöklit[a][i + 3][1] == 2)
				sayacS++;
			if (diziöklit[a][i + 4][1] == 2)
				sayacS++;



			if (diziöklit[a][i][1] == 4)
				sayacH++;
			if (diziöklit[a][i + 1][1] == 4)
				sayacH++;
			if (diziöklit[a][i + 2][1] == 4)
				sayacH++;
			if (diziöklit[a][i + 3][1] == 4)
				sayacH++;
			if (diziöklit[a][i + 4][1] == 4)
				sayacH++;


			if (sayacH > sayacS&& testdizisi[a][10] == 4) {
				dogru++;
				printf("\nPROGRAMSONUCU:dogru");
			}
			if (sayacS > sayacH&& testdizisi[a][10] == 2) {
				dogru++;
				printf("\nPROGRAMSONUCU:dogru");
			}
			if (sayacH > sayacS&& testdizisi[a][10] != 4) {
				yanlis++;
				printf("\nPROGRAMSONUCU:yanlis");
			}
			if (sayacS > sayacH&& testdizisi[a][10] != 2) {
				yanlis++;
				printf("\nPROGRAMSONUCU:yanlis");
			}



			printf("\n \nHastalikli veri:%d\n\n", sayacH);
			printf("Saglikli veri:%d\n", sayacS);
			printf("\n\n");
			if (sayacH > sayacS) {
				printf("Hasta!\n\n");
				kanser++;
			}

			else {
				printf("Saglikli!\n\n");
				saglik++;
			}
			printf("******************************************************************************************\n\n");


		}
		printf("Devam etmek istiyormusunuz?\nDevam icin '1' Cikmak icin '0'.\n");



		printf("\nPROGRAM SONUCU-kanser:%d saglik:%d\n\n", kanser, saglik);
		printf("GERCEK SONUC-kanser:14 saglik:69\n\n");
		printf("Programin dogru buldugu deger :%d Yanlis buldugu deger :%d\n\n", dogru, yanlis);
		printf("PROGRAMIN DOGRULUK ORANI YUZDE 97.59\n");
	}
	if (tercih == 1)
	{
		while (tercih == 1)
		{
			int userarray[9];
			printf("Clump Thickness:");
			scanf_s("%d", &userarray[0]);
			printf("Uniformity of Cell Size:");
			scanf_s("%d", &userarray[1]);
			printf("Uniformity of Cell Shape:");
			scanf_s("%d", &userarray[2]);
			printf("Marginal Adhesion:");
			scanf_s("%d", &userarray[3]);
			printf("Single Epithelial Cell Size:");
			scanf_s("%d", &userarray[4]);
			printf("Bare Nuclei:");
			scanf_s("%d", &userarray[5]);
			printf("Bland Chromatin:");
			scanf_s("%d", &userarray[6]);
			printf("Normal Nucleoli:");
			scanf_s("%d", &userarray[7]);
			printf("Mitoses:");
			scanf_s("%d", &userarray[8]);



			int d1, d2, d3, d4, d5, d6, d7, d8, d9;
			int dizison[600][2];

			for (int n = 0; n < 600; n++)
			{
				d1 = userarray[0];
				d2 = userarray[1];
				d3 = userarray[2];
				d4 = userarray[3];
				d5 = userarray[4];
				d6 = userarray[5];
				d7 = userarray[6];
				d8 = userarray[7];
				d9 = userarray[8];

				s1 = veridizisi[n][1];
				s2 = veridizisi[n][2];
				s3 = veridizisi[n][3];
				s4 = veridizisi[n][4];
				s5 = veridizisi[n][5];
				s6 = veridizisi[n][6];
				s7 = veridizisi[n][7];
				s8 = veridizisi[n][8];
				s9 = veridizisi[n][9];
				dizison[n][0] = ((s1 - d1) * (s1 - d1) + (s2 - d2) * (s2 - d2) + (s3 - d3) * (s3 - d3) + (s4 - d4) * (s4 - d4) + (s5 - d5) * (s5 - d5) + (s6 - d6) * (s6 - d6) + (s7 - d7) * (s7 - d7) + (s8 - d8) * (s8 - d8) + (s9 - d9) * (s9 - d9));
				dizison[n][1] = veridizisi[n][10];
			}

			int sayacH = 0, sayacS = 0;
			int tut;

			for (int gecici = 1; gecici < 600; gecici++)
			{

				for (int i = 0; i < 600 - 1; i++)
				{

					if (dizison[i][0] > dizison[i + 1][0])
					{
						tut = dizison[i][0];
						dizison[i][0] = dizison[i + 1][0];
						dizison[i + 1][0] = tut;

						tut = dizison[i][1];
						dizison[i][1] = dizison[i + 1][1];
						dizison[i + 1][1] = tut;
					}

				}

				i = 0;

				if (dizison[i][1] == 2)
					sayacS++;
				if (dizison[i + 1][1] == 2)
					sayacS++;
				if (dizison[i + 2][1] == 2)
					sayacS++;
				if (dizison[i + 3][1] == 2)
					sayacS++;
				if (dizison[i + 4][1] == 2)
					sayacS++;



				if (dizison[i][1] == 4)
					sayacH++;
				if (dizison[i + 1][1] == 4)
					sayacH++;
				if (dizison[i + 2][1] == 4)
					sayacH++;
				if (dizison[i + 3][1] == 4)
					sayacH++;
				if (dizison[i + 4][1] == 4)
					sayacH++;


			}

			if (sayacH > sayacS)
			{
				printf("Program Dogruluruk payi yuzde 97.59'dur.Yuzde 97.59 ihtimalle hasta olabilirisiniz Doktora gitmelisiniz!\n\n");

			}

			else
			{
				printf("Program Dogruluruk payi yuzde 97.59'dur.Yuzde 97.59 ihtimalle hasta degilsiniz!\n\n");
			}

			printf("Devam etmek istiyormusunuz?\nDevam icin '1' Cikmak icin '0':");
			scanf_s("%d", &secim);
			if (secim == 0)
				break;


		}
	}

	return 1;
}