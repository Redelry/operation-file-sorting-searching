        #include <stdio.h>
        #include <string.h>
        #include <iostream>
        using namespace std;
        
        struct Laptop
        {
            char LaptopName[100];
            int Battery,Panel,code;
            float ProcSpd;
        };
        struct Laptop array[100];
        void swap(struct Laptop *e, struct Laptop *f) //fungsi swap
        {
            struct Laptop temp = *e; // mengisi nilai temp dengan nilai e
            *e = *f; // mengganti nilai e dengan nilai f
            *f = temp; // mengganti nilai f dengan nilai temp
        }

        void heapify(struct Laptop arr[], int n, int i) // proses pengurutan
        {
            int largest = i; // mengisi nilai largest dengan nilai i
            int left = 2 * i + 1; // merumuskan nilai left
            int right = 2 * i + 2; // merumuskan nilai right

            if (left < n && arr[left].code > arr[largest].code) // jika n kurang dari left dan isi indeks left lebih dari isi indeks largest
                largest = left; // ganti nilai largest dengan nilai left

            if (right < n && arr[right].code > arr[largest].code)//jika n kurang dari right dan isi indeks right lebih dari isi indeks largest
                largest = right; // ganti nilai largest dengan nilai right


            if (largest != i) // jika nilai largest tidak sama dengan i
            {
                swap(&arr[i], &arr[largest]); //swap nilai i dengan nilai largest
                heapify(arr, n, largest); // masukkan ke fungsi heapify
            }
        }


    void heapSort(struct Laptop arr[], int n) //fungsi heapsort
    {
        for (int i = n / 2 - 1; i >= 0; i--) // untuk nilai i=n/2-1 hingga i lebih dari sama dengan 0 dengan decrement, lakukan heapify
            heapify(arr, n, i);
        for (int i = n - 1; i >= 0; i--) { // untuk nilai i=n-1 hingga i lebih dari sama dengan 0 dengan decrement, lakukan swap dan heapify
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
    }

    int main() 
    { 
    FILE *fileFP; 
    fileFP=fopen("DataLaptop.txt", "w+");
 
    char temp[100];
    int input, posisi, swap;
    printf("\n==== MENCATAT DATA Laptop =====\n\n");
    printf("Masukkan jumlah Laptop yang diinput: ");
    scanf("%d", &input);
    struct Laptop get[input];
    struct Laptop temps;
    
    int i;
    for(i = 0; i < input; i++) {
        printf("\nInput Data Laptop ke - %d\n", i+1);
        printf("Masukkan Kode Produk (angka)\t\t: ");
        scanf("%d", &get[i].code);
        printf("Input Merk Laptop\t\t\t: ");
        scanf("%c", temp);
        scanf("%[^\n]", &get[i].LaptopName);
        printf("Input Ukuran Battery (angka MAh)\t: ");
        scanf("%d", &get[i].Battery);
        printf("Input Kecepatan Processor (angka GHz)\t: ");
        scanf("%f", &get[i].ProcSpd);
        printf("Input tingkat warna layar (angka sRGB)\t: ");
        scanf("%d", &get[i].Panel);
        printf("\nData ke %d : %d\t\t%s\t%d MAh \t %0.2f GHz\t%d sRGB\n", i+1, get[i].code, get[i].LaptopName, get[i].Battery, get[i].ProcSpd, get[i].Panel);
 
        fprintf(fileFP, "%d \t %s \t %d \t %.1f \t %d\n", get[i].code, get[i].LaptopName, get[i].Battery, get[i].ProcSpd, get[i].Panel);
    }
        fclose(fileFP);

        int size;
        char ch;
        int count = input;
        fopen("DataLaptop.txt", "r");

    
        for (int i = 0; i < count; i++) { 
		
            fscanf(fileFP, "%d %s %d %f %d\n", &array[i].code, array[i].LaptopName, &array[i].Battery, &array[i].ProcSpd, &array[i].Panel);
            printf("\n%d %s %d %0.1f %d\n", array[i].code, array[i].LaptopName, array[i].Battery, array[i].ProcSpd, array[i].Panel);
           
        }
    heapSort(array, count);
    printf("\nSetelah pengurutan menggunakan kode produk\n");
    
    fileFP=fopen("DataLaptop.txt", "w+"); //membuka file dengan perintah w+ untuk read and write 
    for (int i=0; i<count; i++) //untuk nilai i hingga nilai count, lakukan
    {
        printf("No. Seri %d \t%s\t%d MAh \t %0.2f GHz\t%d sRGB\n", array[i].code, array[i].LaptopName,array[i].Battery,array[i].ProcSpd,array[i].Panel);
        fprintf(fileFP, "%d \t %s \t %d \t %.1f \t %d\n", array[i].code, array[i].LaptopName, array[i].Battery, array[i].ProcSpd, get[i].Panel);
    }
    fclose(fileFP);

fopen("DataLaptop.txt", "r"); //membuka file dengan perintah r untuk read 

    
        for (int i = 0; i < count; i++) {  //untuk nilai i hingga nilai count, lakukan
		
            fscanf(fileFP, "%d %s %d %f %d\n", &array[i].code, array[i].LaptopName, &array[i].Battery, &array[i].ProcSpd, &array[i].Panel);
            printf("%d %s %d %0.1f %d\n", array[i].code, array[i].LaptopName, array[i].Battery, array[i].ProcSpd, array[i].Panel);
           
        }
    int find; // deklarasikan variabel find bertipe integer
    int index=0; // deklarasikan indeks = 0
    printf("Mencari Data Berdasarkan No. Seri : ");
    scanf("%d", &find); // menyimpan data yang ingin dicari user dalam variabel find

    int mid, low = 0, high = input-1; // deklarasikan variabel mid, low = 0, high = input -1 bertipe integer
    while(array[low].code < find && array[high].code > find) { // jika data yang dicari berada diantara low dan high, maka
    mid = ((find-array[low].code) / (array[high].code-array[low].code)) * (high-low) + low; // masukkan nilai mid ke dalam rumusan
    if(array[mid].code < find){ // jika nilai mid kurang dari nilai find
    low = mid + 1; // ganti nilai low dengan nilai mid + 1

    }
    else if(array[mid].code > find){ // jika nilai mid lebih dari nilai find
        high = mid - 1; // ganti nilai high dengan nilai mid - 1
    }

    else{
    index=mid; // jika tidak memenuhi kedua kondisi diatas maka indeks = mid
    break;
    }
}
    if (array[low].code == find){ // jika nilai low sama dengan nilai find
    index = low; // indeks sama dengan low
}

    else if(array[high].code == find){ // jika nilai high sama dengan find
    index = high; // indeks sama dengan high
    } 
    else(index=-1); // jika tidak keduanya indeks = -1
    if(index!=-1){ // jika indeks tidak sama dengan -1, maka
    printf("Data berada pada urutan ke-%d\n",index+1); // tampilkan urutan nilai indeks pada terminal
    }
    else{ // jika indeks = -1
    printf("Data tidak ditemukan"); // tampilkan data tidak ditemukan
    }
    return 0;
}