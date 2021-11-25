int area = 0;
    int sub = 0;

    for(int i = 0; i < input1; i++){
        area += abs(input2[i][1] - input2[i][0]);
    }

 for(int i = 0; i < input1-1; i++){
    if(input2[i][1] - input2[i+1][0] >= 0)
            sub += input2[i][1] - input2[i+1][0];
    }

    return (area - sub);
}