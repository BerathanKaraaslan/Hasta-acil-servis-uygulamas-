#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define HL7_FILE "patients.hl7"

typedef struct {
    int id;
    char name[50];
    int age;
    char condition[100];
    int priority; // 1 (en acil) - 5 (daha az acil)
    int prescription_no;
} Patient;

Patient queue[MAX_PATIENTS];
int patient_count = 0;

// Hasta ekleme
void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Hasta kapasitesi dolu!\n");
        return;
    }

    Patient p;
    p.id = patient_count + 1;
    printf("Hasta adi: ");
    getchar(); // Onceki girisin tamponunu temizle
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Yeni satiri kaldir

    printf("Yas: ");
    scanf("%d", &p.age);
    getchar(); // Tampon temizleme

    printf("Hastalik/Sikayet: ");
    fgets(p.condition, sizeof(p.condition), stdin);
    p.condition[strcspn(p.condition, "\n")] = 0;

    printf("Oncelik (1-5, 1 en acil): ");
    scanf("%d", &p.priority);
    p.prescription_no = 0;

    queue[patient_count++] = p;
    printf("Hasta kaydedildi. ID: %d\n", p.id);
}

// Oncelik sirasi ile siralama (Bubble Sort)
void sort_patients() {
    for (int i = 0; i < patient_count - 1; i++) {
        for (int j = 0; j < patient_count - i - 1; j++) {
            if (queue[j].priority > queue[j + 1].priority) {
                Patient temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

// Muayene islemi
void process_patient() {
    if (patient_count == 0) {
        printf("Bekleyen hasta yok.\n");
        return;
    }
    sort_patients();

    Patient *p = &queue[0];
    printf("Hasta muayene ediliyor: %s (ID: %d, Oncelik: %d)\n", p->name, p->id, p->priority);
    p->prescription_no = rand() % 10000 + 1000;
    printf("Recete No: %d\n", p->prescription_no);

    // Hastayi listeden cikar
    for (int i = 1; i < patient_count; i++) {
        queue[i - 1] = queue[i];
    }
    patient_count--;
}

// Hasta listesini HL7 formatinda kaydetme
void save_to_hl7() {
    FILE *file = fopen(HL7_FILE, "w");
    if (!file) {
        printf("Dosya acilamadi!\n");
        return;
    }

    for (int i = 0; i < patient_count; i++) {
        fprintf(file, "PID|%d|%s|%d|%s|%d|%d\n", queue[i].id, queue[i].name, queue[i].age, queue[i].condition, queue[i].priority, queue[i].prescription_no);
    }
    fclose(file);
    printf("HL7 formatinda hasta verileri kaydedildi.\n");
}

// Hasta listesini gosterme
void display_patients() {
    if (patient_count == 0) {
        printf("Bekleyen hasta yok.\n");
        return;
    }
    printf("ID | Ad | Yas | Sikayet | Oncelik | Recete No\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < patient_count; i++) {
        printf("%d | %s | %d | %s | %d | %d\n", queue[i].id, queue[i].name, queue[i].age, queue[i].condition, queue[i].priority, queue[i].prescription_no);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nAcil Servis Sistemi\n");
        printf("1. Hasta Kaydi\n2. Muayene\n3. Hasta Listesi\n4. HL7 Kaydet\n5. Cikis\nSecim: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                process_patient();
                break;
            case 3:
                display_patients();
                break;
            case 4:
                save_to_hl7();
                break;
            case 5:
                printf("Cikis yapiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
}
