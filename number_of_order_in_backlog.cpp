// 1801. Number of Orders in the Backlog
// Medium
// 220
// 201
// Companies
// You are given a 2D integer array orders, where each orders[i] = [pricei, amounti, orderTypei] denotes that amounti orders have been placed of type orderTypei at the price pricei. The orderTypei is:

// 0 if it is a batch of buy orders, or
// 1 if it is a batch of sell orders.
// Note that orders[i] represents a batch of amounti independent orders with the same price and order type. All orders represented by orders[i] will be placed before all orders represented by orders[i+1] for all valid i.

// There is a backlog that consists of orders that have not been executed. The backlog is initially empty. When an order is placed, the following happens:

// If the order is a buy order, you look at the sell order with the smallest price in the backlog. If that sell order's price is smaller than or equal to the current buy order's price, they will match and be executed, and that sell order will be removed from the backlog. Else, the buy order is added to the backlog.
// Vice versa, if the order is a sell order, you look at the buy order with the largest price in the backlog. If that buy order's price is larger than or equal to the current sell order's price, they will match and be executed, and that buy order will be removed from the backlog. Else, the sell order is added to the backlog.

// Return the total amount of orders in the backlog after placing all the orders from the input. Since this number can be large, return it modulo 109 + 7.
class Solution {
public:
     class comp{
        public:
        bool operator()(pair<int,int>const &a, pair<int,int>const &b)
        {
            return a.first>b.first;
        }
     };
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>sell;
        priority_queue<pair<int,int>,vector<pair<int,int>>>buy;
        for(auto batch:orders)
        {
            if(batch[2]==0)
            { 
              while(batch[1]!=0){
             if(!sell.empty())
             {
                if(sell.top().first<=batch[0])
                {
                    if(sell.top().second<=batch[1])
                     {
                         batch[1]-=sell.top().second;
                         sell.pop();
                     }
                     else
                     {
                         pair<int,int>p1;
                         p1.first= sell.top().first;
                         p1.second= sell.top().second-batch[1];
                         sell.pop();
                         sell.push(p1);
                         batch[1]=0;
                     }

                }
                else
                { pair<int,int>p1;
                p1.first=batch[0] ;
                 p1.second= batch[1];
                 buy.push(p1);
                     batch[1]=0;
                }
             }
             else
             {
                 pair<int,int>p1;
                p1.first=batch[0] ;
                 p1.second= batch[1];
                 buy.push(p1);
                     batch[1]=0;
             }
            }
            }
            else
            {
              while(batch[1]!=0){
             if(!buy.empty())
             {
                if(buy.top().first>=batch[0])
                {
                    if(buy.top().second<=batch[1])
                     {
                         batch[1]-=buy.top().second;
                         buy.pop();
                     }
                     else
                     {
                         pair<int,int>p1;
                         p1.first= buy.top().first;
                         p1.second= buy.top().second-batch[1];
                         buy.pop();
                         buy.push(p1);
                         batch[1]=0;
                     }

                }
                else
                {
                     pair<int,int>p1;
                p1.first=batch[0] ;
                 p1.second= batch[1];
                 sell.push(p1);
                     batch[1]=0;
                }
             }
             else
             {
                pair<int,int>p1;
                p1.first=batch[0] ;
                 p1.second= batch[1];
                 sell.push(p1);
                     batch[1]=0;
             }
            }
            }
        }
        long remsell=0;
        while(!sell.empty())
        {
           remsell+=sell.top().second;
           sell.pop();
        }
        long rembuy=0;
        while(!buy.empty())
        {
           remsell+=buy.top().second;
           buy.pop();
        }
      return (rembuy+remsell)%1000000007;
        
    }
};