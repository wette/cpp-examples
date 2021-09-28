

int main() {
    int i = 4;

    const int MAX_VALUE = 100;
    //MAX_VALUE = 8;  /* nicht erlaubt einen const int zu verändern */

    const int *p = new int(100);
    //*p = 1;       /* ändern des Inhaltes nicht erlaubt, denn der Pointer zeigt auf einen const int */
    p = &i;         /* wir dürfen den Zeiger aber auf eine andere Adresse zeigen lassen! */
    //*p = 10;      /* auch nicht, obwohl i kein const ist, denn p ist ein const int Zeiger. Also geht das nicht */

    int* const q = new int(100);
    *q = 10;        /* ändern des Inhaltes erlaubt */
    //q = &i;       /* wir dürfen den Zeiger aber NICHT auf eine andere Adresse zeigen lassen! */

    const int * const r = new int(100);
    //*r = 10;      /* Ändern des Inhaltes nicht erlaubt */
    //r = &i;       /* Ändern der Adresse nicht erlaubt */



    return 0;
}