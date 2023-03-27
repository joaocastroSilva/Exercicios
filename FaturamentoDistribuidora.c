#include <stdio.h>

int main() {
    float sp = 67836.43;
    float rj = 36678.66;
    float mg = 29229.88;
    float es = 27165.48;
    float outros = 19849.53;

    float total = sp + rj + mg + es + outros;

    float porcentSP = (sp / total) * 100;
    float porcentRJ = (rj / total) * 100;
    float porcentMG = (mg / total) * 100;
    float porcentES = (es / total) * 100;
    float porcent = (outros / total) * 100;

    printf("Percentual de representacao:\n");
    printf("SP: %.2f%%\n", porcentSP);
    printf("RJ: %.2f%%\n", porcentRJ);
    printf("MG: %.2f%%\n", porcentMG);
    printf("ES: %.2f%%\n", porcentES);
    printf("Outros: %.2f%%\n", porcent);

    return 0;
}
