        ll l3 = -1, r3 = s[0]+1-a[3]-a[2];
        // a[3] としてあり得るものをやっていく。
        while(r3 - l3 > 1){
            int m3 = l3 + (r3 - l3) / 2;
            // M3
            bool m3fin=false;
            for(int i = 0; i < n + 3; i += 3){
                // beta+kみたいなのを考えないといけない
                ll now3=m3;
                if(i-3>=0){
                    now3 += s[i-3] - s[i-3];
                }
                a[i] = now3;
                if(now3 < 0){
                    // 制約違反してしまたｔので、l3かr3をいじらないといけない。どっち?
                    // 小さくなった結果now3が負になってしまったので、大きくしないといけない
                    l3 = m3;
                    m3fin = true;
                    break;
                }
                for(int j = i; j >= i-3; i--){
                    if(m3 + a[i+1] >s[j]){
                        // m3はデカすぎるので、小さくする必要がある
                        r3=m3;
                        // M3まで戻る
                        m3fin = true;
                        break;
                    }
                }
                if(m3fin){
                    break;
                }
                // m3 でokの時、ここまでくる, 次は、m3 を決める
            }
            // m3finの時ここまで来る
            if(m3fin) continue;
        }