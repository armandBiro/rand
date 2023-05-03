#include <stdio.h>

int main(){

	FILE* bemenet = fopen("be.txt", "r");

    // Elso sor beolvasasa --> latotavolsag, varosok szama
	int latotavolsag, varosok_szama;
	fscanf(bemenet, "%d\n%d", &latotavolsag, &varosok_szama);

    // Varosok kozotti tavolsagok beolvasasa (eggyel kevesebb tav van mint ahany varos)
	int tavok[varosok_szama - 1];
	for(int i = 0; i < varosok_szama - 1; i++){
		fscanf(bemenet, "%d", &tavok[i]);
	}

    //Bemeneti fajl bezarasa
	fclose(bemenet);


    // Inicializaljuk a nyero varos indexet tarolo, es a lathato varosok maximumat tarolo valtozokat
	int nyero_varos = -1, lathato_max = -1;

    //Vegigiteralunk a varosokon es mindig updateljuk a nyero varos indexet
    //es a maximum lathato varosokat, ha nagyobb erteket kapunk
	for(int i = 0; i < varosok_szama; i++){
        // Minden varos iteraciojaban csinalunk egy valtozot,
        //ami nyilvatartja, hogy az aktualis varos hany varosbol lathato
		int lathato = 0;

        //Eloszor mindig az aktualis varostol balra talalhato varosokat vizsgaljuk
        //(ezert megyunk az aktualis i - 1-edik indextol az elso, 0.-ig, visszafele)
        //es noveljuk a tavolsagot --> ha az nagyobb, mint a latotav, akkor
        //mar nem is kell balra tovabb nezelodni
		int tavolsag = 0;
		for(int j = i - 1; j >= 0; j--){
			tavolsag += tavok[j];
			if(tavolsag <= latotavolsag){
				lathato++;
			} else {
				break;
			}
		}

        //Ugyanez a jobb oldalon, az aktualis varos utanitol az utolso varosig megyunk
		tavolsag = 0;
		for(int k = i + 1; k < varosok_szama; k++){
			tavolsag += tavok[k - 1];
			if(tavolsag <= latotavolsag){
				lathato++;
			} else {
				break;
			}
		}

        //Ha mindez megvolt, akkor csekkoljuk, hogy a most vizsgalt varos
        //tobb varosbol lenne-e lathato, mint az eddigi maximum
		if(lathato > lathato_max){
			lathato_max = lathato;
			nyero_varos = i;
		}
	}


    // Kiirjuk a nyero varos indexet
	printf("%d\n", nyero_varos);

	return 0;
}