NODO *borrar(Lista *L, int dato){
    NODO *p, *auxSig, *auxAnt;
    p=L->h;
    while(p->sig!=NULL){
        if(p->info==dato){
            if(p->sig!=NULL&&p->ant!=NULL){
                auxSig=p->sig;
                auxAnt=p->ant;
                auxSig->ant=auxAnt;
                auxAnt->sig=auxSig;
            }else if(p->sig==NULL){
                auxAnt=p->ant;
                auxAnt->sig=NULL;
                p->ant=NULL;
            }else if(p->ant==NULL){
                auxSig=p->sig;
                auxSig->ant=NULL;
                p->sig=NULL;
            }
            p->sig=NULL;
            p->ant=NULL;
            return p;
        }
        p=p->sig;
    }
    return NULL;
}
