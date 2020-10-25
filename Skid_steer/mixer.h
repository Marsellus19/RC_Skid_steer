
#ifndef mixer_h
#define mixer_h

class Mix{
    int output;
public:

    int connstrain(int input, int min, int max){
        if(input < min) return min;
        else if(input > max) return max;
        else return input;
    }

    int add(int ch1, int ch2){
        output = ch1 + ch2 - 1500;
        output = connstrain(output, 1000, 2000);
        return output;
    }


    int substract(int ch1, int ch2){
        output = ch1 - ch2 + 1500;
        output = connstrain(output, 1000, 2000);
        return output;
    }


    int reverse(int input){
        return 1000+ (2000 - input);
    }

}mix;



#endif /* mixer_h */
