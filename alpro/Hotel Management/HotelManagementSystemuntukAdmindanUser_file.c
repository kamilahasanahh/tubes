#include<stdio.h>
#include<stdlib.h>

struct login{
    char name[30];
    char useru[30];
    char passu[20];
};

struct CustomerDetails{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
	char harga[10];
	char jasa[10];
	char refund[10];
	char riwayat[10];
	char transaksi[10];
}s;

void useregis(void);
void userlog(void);
void adminlog(void);
void add();
void list();
void edit();
void delete1();
void search();
void harga();
void jasa();
void refund();
void adduser();
void history();
void wallet();
void jasauser();
void refunduser();
void menuuser(void);
void menuadmin(void);

int main (void){
    int option1, option2;
    system("cls");
    printf("\t\t*********************************************\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*       ----------------------------        *\n");
	printf("\t\t*              MAIN       MENU              *\n");
	printf("\t\t*       ----------------------------        *\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*********************************************\n\n\n");
    printf("\tTekan '1' untuk Admin\t\tTekan '2' untuk User\n\n");
    scanf("%d",&option1);
    getchar();         
    if(option1 == 1){
    		system("CLS");
            adminlog();}
    else if(option1 == 2){
    		system("CLS");
    		printf("\t\t*********************************************\n");
			printf("\t\t*                                           *\n");
			printf("\t\t*       ----------------------------        *\n");
			printf("\t\t*           USER    MAIN     MENU           *\n");
			printf("\t\t*       ----------------------------        *\n");
			printf("\t\t*                                           *\n");
			printf("\t\t*********************************************\n\n\n");
            printf("\tTekan '3' untuk User Regisrasi\t\tTekan '4' untuk User Login\n\n");
    		scanf("%d",&option2);
    		getchar();         
    			if(option2 == 3){
            		system("CLS");
            		useregis();}
    			else if(option2 == 4){
            		system("CLS");
            		userlog();}
	}
}
      
void useregis(void){
    char username[30],password[20];
    struct login l;
    printf("\nSilahkan isi nama lengkap.\n\n");
    printf("\nInput nama:\n");
    scanf("%s",l.name); fflush(stdin);
    printf("\nSilahkan isi detail login yang ingin digunakan."); 
    printf("\nInput username:\n");
    scanf("%s",l.useru);
    printf("\nInput password:\n");
    scanf("%s",l.passu);
    printf("\nRegistrasi selesai! Tekan enter untuk lanjut login.\n");
    printf("*********************************************\n");
    getchar();
    printf("\nInput username:\n");
    scanf("%s",&username); getchar();
    printf("\nInput password:\n");
    scanf("%s",&password);
    if(strcmp(username,l.useru)==0){
    	if(strcmp(password,l.passu)==0){
        printf("\nWelcome! Login success!");}
	else{
    printf("\nPassword salah!");}
	}
	else{
    printf("\nUser tidak ditemukan!");}
getch();
system("cls");
menuuser();
}
    
    void userlog (void){
    char username[15];
    char password[12];
    printf("Input username:\n");
    scanf("%s",&username);
    printf("Input password:\n");
    scanf("%s",&password);
    if(strcmp(username,"user")==0){
        if(strcmp(password,"user")==0){
        printf("\nWelcome! Login success!");}
	else{
    printf("\nPassword salah!");}
    }
	else{
    printf("\nUser tidak ditemukan!");}
getch();
system("cls");
menuuser();
}

void adminlog (void){
    char username[15];
    char password[12];
    printf("Input username:\n");
    scanf("%s",&username);
    printf("Input password:\n");
    scanf("%s",&password);
    if(strcmp(username,"admin")==0){
        if(strcmp(password,"admin")==0){
        printf("\nWelcome! Login success!");}
	else{
    printf("\nPassword salah!");}
    }
	else{
    printf("\nUser tidak ditemukan!");}
getch();
system("cls");
menuadmin();
}

void menuadmin(void){
	char choice;
	system("cls");
	printf("\t\t*********************************************\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*       ----------------------------        *\n");
	printf("\t\t*         HOTEL MANAGEMENT SYSTEM           *\n");
	printf("\t\t*       ----------------------------        *\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*********************************************\n\n\n");
	printf(" \n Enter untuk lanjut:");
	getch();
    system("cls");
	while (1){
		system("cls");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		printf("\n\n");
		printf(" \n Enter 1 -> Booking kamar");
		printf(" \n Enter 2 -> Lihat list kamar");
		printf(" \n Enter 3 -> Menghapus rekor kamar");
		printf(" \n Enter 4 -> Mencari rekor kamar");
		printf(" \n Enter 5 -> Edit rekor kamar");
		printf(" \n Enter 6 -> Update harga");
		printf(" \n Enter 7 -> List dan tambah jasa");
		printf(" \n Enter 8 -> Konfirmasi refund user");
		printf(" \n Enter 9 -> Exit");
		choice=getche();
		choice=toupper(choice);
		switch(choice) {
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				harga();break;
			case '7':
				jasa();break;
			case '8':
				refund();break;
			case '9':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				exit(0);
				break;
			default:
				system("cls");
				printf("Operasi tidak ditemukan, enter untuk balik lagi");
				getch();}
	}
}

void add(){
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0){   
		f=fopen("add.txt","w+");
		system("cls");
		printf("Harap tunggu!");
		printf("\n Proses selesai, silahkan enter untuk lanjut! ");
		getch();}
	while(1){
		system("cls");
		printf("\n Input detail pelanggan:");
		printf("\n**************************");
		printf("\n Input nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Input nama:\n");
		scanf("%s",s.name);
		printf("Input alamat:\n");
		scanf("%s",s.address);
		printf("Input No. HP:\n");
		scanf("%s",s.phonenumber);
		printf("Input Kewarganegaraan:\n");
		scanf("%s",s.nationality);
		printf("Input email:\n");
		scanf(" %s",s.email);
		printf("Input masa(\'x\'hari):\n");
		scanf("%s",&s.period);
		printf("Input tanggal datang(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\nKamar telah dibooking!");
		printf("\n Tekan esc untuk selesai, enter untuk lanjut:");
		test=getche();
		if(test==27)
		break;}
	fclose(f);
}

void list(){
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("KAMAR    ");
	printf("NAMA\t ");
	printf("\tALAMAT ");
	printf("\tNOMORHP ");
	printf("\tNKEWARGANEGARAAN ");
	printf("\tEMAIL ");
	printf("\t\t  MASA ");
	printf("\t TANGGAL \n");
	for(i=0;i<118;i++)
	printf("-");
	while(fread(&s,sizeof(s),1,f)==1){
		/*printf("NOMORKAMAR :\t%s\n",s.roomnumber);
		printf("NAMA:\t%s\n",,s.name);
		printf("ALAMAT:\t%s\n",s.address);
		printf("NOMORHP:\t%s\n",s.phonenumber);
		printf("KEWARGANEGARAAN \n");*/
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);}
	printf("\n");
	for(i=0;i<118;i++)
	printf("-");
	fclose(f);
	getch();
}

void delete1(){
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Inputkan nomor kamar yang ingin dihapus: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1){
		if(strcmp(s.roomnumber,roomnumber)==0){       
		i=0;
		continue;}
		else
		fwrite(&s,sizeof(s),1,t);}
	if(i==1){
		printf("\n\n Nomor kamar tidak ditemukan!");
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nPelanggan telah dihapus...");
	fclose(f);
	fclose(t);
	getch();
}

void search(){
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
	exit(0);
	fflush(stdin);
	printf("Inputkan nomor kamar yang ingin dicari: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1){
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRekor ditemukan\n ");
			printf("\nNomor kamar:\t%s",s.roomnumber);
			printf("\nNama:\t%s",s.name);
			printf("\nAlamat:\t%s",s.address);
			printf("\nNomor HP:\t%s",s.phonenumber);
			printf("\nKewarganegaraan:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nMasa:\t%s",s.period);
			printf("\nTanggal datang:\t%s",s.arrivaldate);
			flag=0;
			break;}
	}
	if(flag==1){
		printf("\n\tPelanggan tidak ditemukan!");}
	getch();
	fclose(f);
}

void edit(){
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
	exit(0);
	system("cls");
	printf("Inputkan nomor kamar yang ingin diubah:\n\n");
	scanf("%[^\n]",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1){
		if(strcmp(s.roomnumber,roomnumber)==0){
			k=0;
			printf("\nInput nomor kamar     :");
			gets(s.roomnumber);
			printf("\nInput nama    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nInput alamat        :");
			scanf("%s",&s.address);
			printf("\nInput nomomr HP :");
			scanf("%f",&s.phonenumber);
			printf("\nInput kewarganegaraan :");
			scanf("%s",&s.nationality);
			printf("\nInput email :");
			scanf("%s",&s.email);
			printf("\nInput masa :");
			scanf("%s",&s.period);
			printf("\nInput tanggal datang :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);  //to go to desired position infile
			fwrite(&s,sizeof(s),1,f);
			break;}
	}
	if(k==1){
		printf("\n\nRekor tidak ditemukan!");
		fclose(f);
		getch();}
	else{
	fclose(f);
	printf("\n\n\t\tRekor telah diubah!");
	getch();}
}

void harga(){
	FILE *f;
	int i;
	char test;
	f=fopen("add.txt","a+");
	if(f==0){
		f=fopen("add.txt","w+");
		system("cls");
		getch();}
	while(1){
		system("cls");
		printf("\nInput nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Input harga:\n");
		scanf("%s",s.harga);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\nHarga telah diupdate!");
		printf("\nTekan esc jika selesai atau enter untuk lanjut isi:");
		test=getche();
		if(test==27)
		break;}
	fclose(f);
}

void jasa(){
	FILE *f;
	int i;
	char test;
	f=fopen("add.txt","a+");
	if(f==0){
	   f=fopen("add.txt","w+");
		system("cls");
		getch();}
	while(1){
		system("cls");
		printf("List jasa:\n"); printf("1. Spa:\n"); printf("2. Gym:\n"); printf("3. Travel:\n"); printf("4. Tempat rapat:\n");
		printf("\nInput nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Input jasa yang ingin ditambah:\n");
		scanf("%s",s.jasa);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\nJasa tersebut telah ditambah!");
		printf("\nTekan esc jika selesai dan enter untuk lanjut isi:");
		test=getche();
		if(test==27)
		break;}
	fclose(f);
}

void refunduser(){
	FILE *f;
	int i;
	char test;
	f=fopen("add1.txt","a+");
	if(f==0){
	   f=fopen("add1.txt","w+");
		system("cls");
		getch();}
	while(1){
		system("cls");
		printf("\nInput nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Ajukan refund?(Y/N):\n");
		scanf("%s",s.refund);
		if(strcmp(s.refund, "Y")==0){
			printf("  \n\n\n       Refund telah diajukan, harap tunggu untuk konfirmasi dari pihak staff.");}
		else{
			printf("\n        Refund tidak diajukan.");
			getch();}
   {fwrite(&s,sizeof(s),1,f);
	fflush(stdin);
	printf("\nTekan esc jika selesai dan enter untuk lanjut isi:");
	test=getche();
	if(test==27)
	break;}
	fclose(f);}
}

void menuuser(void){
	char choice;
	system("cls");
	printf("\t\t*********************************************\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*       ----------------------------        *\n");
	printf("\t\t*          HOTEL   USER    SYSTEM           *\n");
	printf("\t\t*       ----------------------------        *\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*********************************************\n\n\n");
	printf(" \n Enter untuk lanjut:");
	getch();
    system("cls");
	while (1){
		system("cls");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		printf("\n\n");
		printf(" \n Enter 1 -> Booking kamar (user)");
		printf(" \n Enter 2 -> Booking jasa");
		printf(" \n Enter 3 -> Refund user");
		printf(" \n Enter 4 -> Riwayat Transaksi");
		printf(" \n Enter 5 -> eWallet");
		printf(" \n Enter 6 -> Exit");
		choice=getche();
		choice=toupper(choice);
		switch(choice){
			case '1':
				adduser();break;
			case '2':
				jasauser();break;
			case '3':
				refunduser();break;
			case '4':
				history();break;
			case '5':
				wallet();break;
			case '6':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				exit(0);
				break;
			default:
				system("cls");
				printf("Operasi tidak ditemukan, enter untuk balik lagi");
				getch();}
	}
}

void adduser(){
	FILE *f;
	char test;
	f=fopen("add1.txt","a+");
	if(f==0){
	   f=fopen("add1.txt","w+");
		system("cls");
		printf("Harap tunggu!");
		printf("\n Proses selesai, silahkan enter untuk lanjut! ");
		getch();}
	while(1){
		system("cls");
		printf("\n Input detail pelanggan:");
		printf("\n**************************");
		printf("\n Input nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Input nama:\n");
		scanf("%s",s.name);
		printf("Input alamat:\n");
		scanf("%s",s.address);
		printf("Input No. HP:\n");
		scanf("%s",s.phonenumber);
		printf("Input Kewarganegaraan:\n");
		scanf("%s",s.nationality);
		printf("Input email:\n");
		scanf(" %s",s.email);
		printf("Input masa(\'x\'hari):\n");
		scanf("%s",&s.period);
		printf("Input tanggal datang(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\nKamar telah dibooking!");
		printf("\n Tekan esc untuk selesai, enter untuk lanjut:");
		test=getche();
		if(test==27)
		break;}
	fclose(f);
}

void jasauser(){
	FILE *f;
	int i;
	char test;
	f=fopen("add1.txt","a+");
	if(f==0){
	   f=fopen("add1.txt","w+");
		system("cls");
		getch();}
	while(1){
		system("cls");
		printf("List jasa:\n"); printf("1. Spa:\n"); printf("2. Gym:\n"); printf("3. Travel:\n"); printf("4. Tempat rapat:\n");
		printf("\nInput nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Input jasa yang ingin ditambah:\n");
		scanf("%s",s.jasa);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\nJasa tersebut telah ditambah!");
		printf("\nTekan esc jika selesai dan enter untuk lanjut isi:");
		test=getche();
		if(test==27)
		break;}
	fclose(f);
}

void refund(){
	FILE *f;
	int i;
	char test;
	f=fopen("add.txt","a+");
	if(f==0){
	   f=fopen("add.txt","w+");
		system("cls");
		getch();}
	while(1){
		system("cls");
		printf("\nInput nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Konfirmasi refund?(Y/N):\n");
		scanf("%s",s.refund);
		if(strcmp(s.refund, "Y")==0){
			printf("  \n\n\n       Refund telah dikonfirmasi.");}
		else{
			printf("\n        Refund belum dikonfirmasi.");
			getch();}
   {fwrite(&s,sizeof(s),1,f);
	fflush(stdin);
	printf("\nTekan esc jika selesai dan enter untuk lanjut isi:");
	test=getche();
	if(test==27)
	break;}
	fclose(f);
}
}

void history(){
FILE *f;
	int count=0;
    int num; 
    int arr[100],i=0;
	char test, nokamar[10];
	f=fopen("add1.txt","a+");
	if(f==0){   
		f=fopen("add1.txt","w+");
		system("cls");
		printf("Harap tunggu!");
		printf("\n Proses selesai, silahkan enter untuk lanjut! ");
		getch();}
	while(1){
		system("cls");
		printf("\n Input detail transaksi:");
		printf("\n**************************");
		printf("\n Input nomor kamar:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		while(num!=-1){
			printf("Input nominal transaksi (enter -1 jika selesai):\n");
			count+=scanf("%d",&num);
        	arr[i++]=num;}
		printf("\n**************************");
		printf("\n Input nomor kamar untuk melihat riwayat transaksi:\n");
		scanf("\n%s",nokamar); getchar(); 
		if(strcmp(s.roomnumber,nokamar)==0){
        	printf("\nNomor kamar ditemukan!");
			printf("\nRiwayat transaksi: %d\n", count);
			printf("Nominal yang diisi:\n");
    		for(i=0;i<count;i++){
       			printf("%d \n",arr[i]);}}
		else{
    		printf("\nNomor kamar tidak ditemukan!");}
			fwrite(&s,sizeof(s),1,f);
			fflush(stdin);
			printf("\nTekan esc jika selesai dan enter untuk lanjut isi:");
			test=getche();
			if(test==27)
			break;}
	fclose(f);
}

void wallet(){
	FILE *f;
	char test;
	int deposit, withdraw, balance=0;                                                                                                                  
	char op; 
	f=fopen("add1.txt","a+");
	if(f==0){
	   f=fopen("add1.txt","w+");
		system("cls");
		printf("Harap tunggu!");
		printf("\n Proses selesai, silahkan enter untuk lanjut! ");
		getch();}
	while(1){
		system("cls");                                                               
  		printf("\neWallet");                                                   
 		printf("\n................");                                                 
		printf("\nD ->Deposit");                                                     
  		printf("\nW ->Withdraw");                                                    
  		printf("\nB ->Balance");                                                                      
  		printf("\nInput D/W/B: ");                                                
  		scanf(" %c", &op);                                                            
  		switch(op){                                                                             
   			case 'D':                                                                    
     			printf("\nInput deposit: ");                                        
     			scanf("%d", &deposit);                                                   
     			balance += deposit;                                                        
     			break;                                                                     
   			case 'W':                                                                    
     			printf("\nInput withdraw: ");                                       
     			scanf("%d", &withdraw);                                                    
     			balance -= withdraw;                                                       
     			break;                                                                     
   			case 'B':                                                                    
     			printf("Balance: %d", balance);                                            
     			break;                                                                           
   			default:                                                                     
     			printf("Operasi eror!"); }
  	printf("\nTekan esc jika selesai dan enter untuk lanjut isi:");
	test=getche();
	if(test==27)
	break;}                  
}
