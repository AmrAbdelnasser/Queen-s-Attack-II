#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int queens_fast_Attack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    int num_moves = 0;
    int vert_obst_bot = 0; //flag
    int vert_obst_top = 0; //flag
    int top_disp = n; //disp
    int bot_disp = n; //disp
    //Horizontal check
    for(int i=0; i<k; ++i)
    {
        if(obstacles[i][1]==c_q) //there is a vert obstacle
        {
            //if(obstacles[i][0]>r_q && !vert_obst_top) //obstacle is on top
            if(obstacles[i][0]>r_q) //obstacle is on top
            {
                vert_obst_top = 1;
                cout<<"Found V obst at "<<obstacles[i][0]<<", "<<obstacles[i][1]<<endl;
                //num_moves = num_moves + obstacles[i][0] - r_q - 1;
                top_disp = min(top_disp, (obstacles[i][0] - r_q - 1));
                //cout<<num_moves<<endl;
            }
            //else if(obstacles[i][0]<r_q && !vert_obst_bot)//obstacle is on bottom
            else if(obstacles[i][0]<r_q )//obstacle is on bottom
            {
                vert_obst_bot = 1;
                cout<<"Found V obst at "<<obstacles[i][0]<<", "<<obstacles[i][1]<<endl;
                //num_moves = num_moves + r_q - obstacles[i][0] - 1;
                bot_disp = min(bot_disp, (r_q - obstacles[i][0] - 1));
                //cout<<num_moves<<endl;
            }
            //break; //found an obstalce. no point of continuing
        }
    }
    if(!vert_obst_bot) //no vert obst on bot
    {
        //cout<<"came here vb "<<num_moves<<endl;
        num_moves = num_moves + r_q - 1;
        cout<<"came here vb "<<num_moves<<endl;
    }
    else
    {
        num_moves+=bot_disp;
        cout<<"bot_disp"<<bot_disp<<endl;
    }
    if(!vert_obst_top) //no vert obst on top
    {
        //cout<<"came here vt "<<num_moves<<endl;
        num_moves = num_moves + n - r_q;
        cout<<"came here vt "<<num_moves<<endl;
    }
    else
    {
        num_moves+=top_disp;
        cout<<"top_disp"<<top_disp<<endl;
    }
    cout<<"Vert movements "<<num_moves<<endl;
    int Horiz_obst_lft = 0;
    int Horiz_obst_right = 0;
    int lft_disp = n; //disp
    int rght_disp = n; //disp
    //Horiz check
    for(int i=0; i<k; ++i)
    {
        if(obstacles[i][0]==r_q) //there is a horiz obstacle
        {
            //if(obstacles[i][1]>c_q && !Horiz_obst_right) //obstacle is on right
            if(obstacles[i][1]>c_q ) //obstacle is on right
            {
                Horiz_obst_right = 1;
                cout<<"Found H obst at "<<obstacles[i][0]<<", "<<obstacles[i][1]<<endl;
                //num_moves = num_moves + obstacles[i][1] - c_q - 1;
                rght_disp = min(rght_disp, obstacles[i][1] - c_q - 1);
                //cout<<num_moves<<endl;
            }
            //else if(obstacles[i][1]<c_q && !Horiz_obst_lft)//obstacle is on left
            else if(obstacles[i][1]<c_q )//obstacle is on left
            {
                Horiz_obst_lft = 1;
                cout<<"Found H obst at "<<obstacles[i][0]<<", "<<obstacles[i][1]<<endl;
                //num_moves = num_moves + c_q - obstacles[i][1] - 1;
                lft_disp = min(lft_disp, c_q - obstacles[i][1] - 1);
                //cout<<num_moves<<endl;
            }
            //break; //found an obstalce. no point of continuing
        }
    }
    if(!Horiz_obst_right) //no horiz obst right
    {
        //cout<<"came here hr "<<num_moves<<endl;
        num_moves = num_moves + n - c_q;
        cout<<"came here hr "<<num_moves<<endl;
    }
    else
    {
        num_moves+=rght_disp;
        cout<<"rght_disp"<<rght_disp<<endl;
    }
    if(!Horiz_obst_lft) //no horiz obst left
    {
        //cout<<"came here hl "<<num_moves<<endl;
        num_moves = num_moves + c_q - 1;
        cout<<"came here hl "<<num_moves<<endl;
    }
    else
    {
        num_moves+=lft_disp;
        cout<<"lft_disp"<<lft_disp<<endl;
    }
    cout<<"Horiz movements "<<num_moves<<endl;
    int obst_NE = 0; //flag
    int obst_NW = 0; //f;ag
    int obst_SE = 0; //flag
    int obst_SW = 0; //flag

    int NE_disp = n; //disp
    int NW_disp = n; //disp
    int SE_disp = n; //disp
    int SW_disp = n; //disp

    int h_disp = 0;
    int v_disp = 0;
    for(int i=0; i<k; ++i)
    {
        h_disp = c_q - obstacles[i][1];
        v_disp = r_q - obstacles[i][0];
        if (abs(h_disp) == abs(v_disp))
        {
            if(h_disp<0 && v_disp<0)
            {
                obst_NE = 1;
                NE_disp = min(NE_disp, abs(h_disp) - 1);
                //num_moves = num_moves + abs(h_disp) - 1;
            }
            else if(h_disp<0 && v_disp>0)
            {
                obst_SE = 1;
                SE_disp = min(SE_disp, abs(h_disp) - 1);
                //num_moves = num_moves + abs(h_disp) - 1;
            }
            else if(h_disp>0 && v_disp>0)
            {
                obst_SW = 1;
                //num_moves = num_moves + abs(h_disp) - 1;
                SW_disp = min(SW_disp, abs(h_disp) - 1);
            }
            else if(h_disp>0 && v_disp<0)
            {
                //cout<<"obst_NW"<<endl;
                obst_NW = 1;
                NW_disp = min(NW_disp, abs(h_disp) - 1);
                //num_moves = num_moves + abs(h_disp) - 1;
                //cout<<num_moves<<endl;
            }
        }
    }
    int tmp1=0;
    int tmp2=0;
    if(!obst_NE)
    {
        cout<<"!obst_NE"<<endl;
        tmp1 = n - r_q;
        tmp2 = n - c_q;
        num_moves = num_moves + min(tmp1, tmp2);
        cout<<num_moves<<endl;
    }
    else
    {
        cout<<"NE_disp"<<NE_disp<<endl;
        num_moves+=NE_disp;
    }
    if(!obst_NW)
    {
        cout<<"!obst_NW"<<endl;
        tmp1 = n - r_q;
        tmp2 = c_q - 1;
        num_moves = num_moves + min(tmp1, tmp2);
        cout<<num_moves<<endl;
    }
    else
    {
        cout<<"NW_disp"<<NW_disp<<endl;
        num_moves+=NW_disp;
    }
    if(!obst_SE)
    {
        cout<<"!obst_SE"<<endl;
        tmp1 = r_q - 1;
        tmp2 = n - c_q;
        num_moves = num_moves + min(tmp1, tmp2);
        cout<<num_moves<<endl;
    }
    else
    {
        cout<<"SE_disp"<<SE_disp<<endl;
        num_moves+=SE_disp;
    }
    if(!obst_SW)
    {
        cout<<"!obst_SW"<<endl;
        tmp1 = r_q - 1;
        tmp2 = c_q - 1;
        num_moves = num_moves + min(tmp1, tmp2);
        cout<<num_moves<<endl;
    }
    else
    {
        cout<<"SW_disp"<<SW_disp<<endl;
        num_moves+=SW_disp;
    }
    return num_moves;
}
// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    //n board dimension
    //r_q, c_q --> queen position
    //obstacles --> 2-D array of the positioned obstacles
    //convert obstavles into a vector of pairs
    vector<pair<int, int>> obstacles_pairs;
    for(int i=0; i<k; ++i)
    {
        obstacles_pairs.push_back({obstacles[i][0], obstacles[i][1]});
    }
    //cout<<(obstacles_pairs[1]).first<<" "<<(obstacles_pairs[1]).second<<endl;
    int num_moves = 0;
    pair<int, int> t{r_q, c_q};
    vector<pair<int, int>>::iterator itr1;
    //go left
    while(t.second > 1)
    {
        (t.second)--;
        //cout<<"Moving left"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    //Put the queen back in position
    t = make_pair(r_q, c_q);
    //go right
    while(t.second < n)
    {
        (t.second)++;
        //cout<<"Moving right"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    //Put the queen back in position
    t = make_pair(r_q, c_q);
    //go up
    while(t.first < n)
    {
        (t.first)++;
        //cout<<"Moving up"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    //Put the queen back in position
    t = make_pair(r_q, c_q);
    //go down
    while(t.first >1)
    {
        (t.first)--;
        //cout<<"Moving down"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    //Put the queen back in position
    t = make_pair(r_q, c_q);
    //go NE
    while(t.first<n && t.second<n)
    {
        (t.first)++;
        (t.second)++;
        //cout<<"Moving NE"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    //Put the queen back in position
    t = make_pair(r_q, c_q);
    //go SE
    while(t.first<n && t.second>1)
    {
        (t.first)++;
        (t.second)--;
        //cout<<"Moving SE"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    //Put the queen back in position
    t = make_pair(r_q, c_q);
    //go SW
    while(t.first>1 && t.second>1)
    {
        (t.first)--;
        (t.second)--;
        //cout<<"Moving SW"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    //Put the queen back in position
    t = make_pair(r_q, c_q);
    //go NW
    while(t.first>1 && t.second<n)
    {
        (t.first)--;
        (t.second)++;
        //cout<<"Moving NW"<<endl;
        //cout<<t.first<<" "<<t.second<<endl;
        itr1 = find(obstacles_pairs.begin(), obstacles_pairs.end(), t);
        if(itr1==obstacles_pairs.end())//i.e. didn't find
        {
            //cout<<"Path clear"<<endl;
            num_moves++;
        }
        else //hit an obstacle
        {
            //cout<<"Hit an obstacle"<<endl;
            break;
        }
    }
    return num_moves;
}

int main()
{
    //pair<int, int> t{2,2};
    //pair<int, int> y{3,2};
/*
    vector< vector<int> > obstacles{{3, 5},
                                    {3, 4},
                                    {2, 3}};


    cout<<queensAttack(5, 3, 1, 2, obstacles)<<endl;
    cout<<queens_fast_Attack(5, 3, 1, 2, obstacles)<<endl;
*/

    srand(time(0));  // Initialize random number generator.
    vector< vector<int> > obstacles;
    int n = 5;
    int k = 3;
    int r,c,rq,cq;
    while(true)
    {
        for (int i=0; i<k; ++i)
        {
            r = (rand() % n) + 1; //1-->n
            c = (rand() % n) + 1; //1-->n
            obstacles.push_back({r,c});
            cout<<r<<", "<<c<<endl;
        }
        rq = (rand() % n) + 1; //1-->n
        cq = (rand() % n) + 1; //1-->n
        cout<<"Qpos = "<<rq<<", "<<cq<<endl;
        //cout<<queensAttack(4, 0, 4, 4, obstacles)<<endl;
        if (queensAttack(n, k, rq, cq, obstacles) != queens_fast_Attack(n, k, rq, cq, obstacles))
        {
            cout<<"Error found"<<endl;
            cout<<queensAttack(n, k, rq, cq, obstacles)<<" vs "<<queens_fast_Attack(n, k, rq, cq, obstacles)<<endl;
            break;
        }
        obstacles.clear();
    }


    //cout<<"1"<<endl;
    //cout<<"Came here"<<endl;
    //cout<<(t==y);
    //vector<pair<int, int>> t1;
    //t1.push_back({1,1});
    //t1.push_back({2,2});

    //cout<<(t1[1]==t);
    //auto it = find(t1.begin(), t1.end(), t);
    //cout<<(it == t1.end());

    /*
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    */
    return 0;
}

/*
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
*/
