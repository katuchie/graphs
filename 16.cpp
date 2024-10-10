#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int INF = 1e9;

std::vector<int> bfs(std::vector<std::vector<int> > &knight, int start){ 
    std::vector<int> dist(knight.size(), INF);
    std::queue<int> q;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        
        int l = knight[v].size();
        for (int i = 0; i < l; i++){
            if(dist[knight[v][i]] > dist[v] + 1){
                dist[knight[v][i]] = dist[v] + 1;
                q.push(knight[v][i]);
            }
        }
    }

    return dist;


}

int main(){
    int stations, lines;
    std::cin >> stations >> lines;
    std::vector<std::vector<int> > graph(stations + 1);


    for (int i = 0; i < lines; i++){
        int st;
        std::cin >> st;
        std::vector<int> q;

        for(int j = 0; j < st; j++){
            int t;
            std::cin >> t;
            q.push_back(t);
        }

        for(int k = 0; k < (int)q.size(); k++){
          for(int h = k + 1; h < (int)q.size();h++){
            graph[q[k]].push_back(q[h]);
            graph[q[h]].push_back(q[k]);
          }
          
          
        }

    }
    
    int start, finish;
    std::cin >> start >> finish;
    
    
    std::vector<int> res = bfs(graph, start);
    
    if (res[finish] - 1 == 1e9 - 1){
      std::cout << -1;
    }else{
      std::cout << res[finish] - 1;
    }
}

