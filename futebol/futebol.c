#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[20];
	int mar, sof, pts, jgs;
} Time;

Time times[30];
int T = 0, G = 0;

int getTime(char *nome){
	int i = 0;
	
	for(i = 0; i < T; i++)
		if(!strcasecmp(nome, times[i].nome))
			return i;
}

inline int diferente(int i){
	Time a = times[i], b = times[i - 1];
	return (a.mar != b.mar || a.sof != b.sof || a.pts != b.pts || a.jgs != b.jgs);
}

int cmp(const void *a, const void *b){
	Time *ta = (Time*)a, *tb = (Time*)b;
	
	int marcados = tb->mar - ta->mar, saldo = (tb->mar - tb->sof) - (ta->mar - ta->sof), pts = tb->pts - ta->pts;
	
	if(pts)
		return pts;
		
	if(saldo)
		return saldo;
		
	if(marcados)
		return marcados;
	
	return strcasecmp(ta->nome, tb->nome);
}

int main(){
	
	int i = 0, pt1 = 0, pt2 = 0, t1 = 0, t2 = 0, v1 = 0, v2 = 0, TOT = 0;
	char name1[20], name2[20];
	float db = 0.0;
	Time aux;
	
	while(1){
		scanf("%d %d", &T, &G);
		
		if(!T && !G)
			break;
		
		for(i = 0; i < T; i++){
			scanf("%s", times[i].nome);
			getchar();
			
			times[i].mar = 0;
			times[i].sof = 0;
			times[i].pts = 0;
			times[i].jgs = 0;
		}
		
		TOT = 0;
		
		for(i = 0; i < G; i++){
			scanf("%s %d - %d %s", name1, &pt1, &pt2, name2);
			getchar();
			
			t1 = getTime(name1);
			t2 = getTime(name2);
			
			v1 = (pt1 > pt2 ? 3 :(pt1 == pt2 ? 1 : 0));
			v2 = (pt2 > pt1 ? 3 :(pt2 == pt1 ? 1 : 0));
			
			times[t1].mar += pt1;
			times[t1].sof += pt2;
			times[t1].pts += v1;
			times[t1].jgs++;
			
			
			times[t2].mar += pt2;
			times[t2].sof += pt1;
			times[t2].pts += v2;
			times[t2].jgs++;
			
			TOT += v1 + v2;
		}
		
		qsort(times, T, sizeof(Time), cmp);
		
		for(i = 0; i < T; i++){
			
			aux = times[i];
			
			if(!i || diferente(i))
				printf("%d.", i + 1);
			else
				printf("   ");
			
			if(aux.jgs > 0){
			
				db = (float) (aux.pts * 100) / (aux.jgs * 3);
				
				printf("%16s%4d%4d%4d%4d%4d%7.2f\n", aux.nome, aux.pts, aux.jgs, aux.mar, aux.sof, (aux.mar - aux.sof), db);
				
			}else
				printf("%16s%4d%4d%4d%4d%4d    N/A\n", aux.nome, aux.pts, aux.jgs, aux.mar, aux.sof, (aux.mar - aux.sof));
		}
		
		printf("\n");
		
	}

	return 0;
}
