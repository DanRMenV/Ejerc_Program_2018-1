int Arania(double radio, double apotema, int material){

    if(apotema - 1< 1){

        material += 6 * radio;
        return material;
    }
    else{

        material += 6 * (radio + 1);
        apotema--;
        radio = 2 * apotema * raiz(3) / 3;
        return Arania(radio, apotema, material);
    }
}
