    // while(true){
    //     if(idx == n && accumulate(bridge.begin(), bridge.end(), 0) == 0){
    //         break;
    //     }
    //     unit_time += 1;
    //     if(accumulate(bridge.begin(), bridge.end(), 0) <= l){
    //         bridge.erase(bridge.begin()); // 가장 앞 원소 제거
    //         bridge.push_back(trucks[idx]);
    //         idx += 1;
    //     }else{
    //         bridge.erase(bridge.begin()); // 가장 앞 원소 제거
    //         bridge.push_back(0);
    //     }
    //     cout << bridge[0] << bridge[1];
    // }
    // cout << unit_time;