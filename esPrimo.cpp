bool EsPrimo(int a, int divi, bool es){
    if(a == 1 || a == 0) return false;
    if(divi == 1){

        return es;
    }
    else{

        if(SiEsDivisible(a, divi)){

            return false;
        }
        divi--;

        return EsPrimo(a, divi, es);
    }
}
