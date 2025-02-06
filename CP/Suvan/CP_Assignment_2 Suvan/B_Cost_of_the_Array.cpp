// // #include <bits/stdc++.h>
// // using namespace std;
// // typedef vector<int> vi;
// // typedef set<int> s;
// // #define sz(a) int((a).size())
// // #define pb push_back
// // #define all(c) (c).begin(), (c).end()
// // #define present(c, x) ((c).find(x) != (c).end())

// // void fast_io() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
// // }

// // int main() {
// //     fast_io();

// //     int test = 1;
// //     cin >> test;
// //     while(test--) {
// //         int n,k;
// //         cin>>n>>k;
// //         vi num(n);
// //         for(int i = 0; i<n; i++){
// //             cin>>num[i];
// //         }
// //         int ans = 1;
// //         float r = (float)n/k;
// //         if(r == floor(r)){
// //             while(1){
// //             r+=1;
// //             if(ans == num[r]){
// //                 r +=2;
// //                 ans++;
// //             }
// //             else{
// //                  r = r-1;
// //                 break;
// //             }}
// //         }
// //         else{
// //             r = floor(r);
// //             r +=1;
// //             while(1){
// //              if(ans == num[r]){
// //                 r +=2;
// //                 ans++;
// //             }
// //             else{
// //                 r = r-1;
// //                 break;
// //             }}
// //         }
// //         cout<<ans<<endl;
// //     }

// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// void fast_io() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// }

// int main() {
//     fast_io();
    
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, k;
//         cin >> n >> k;
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }
        
//         int required = k / 2;
//         int current = 1;
//         int count = 0;
        
//         for (int i = 0; i < n; ++i) {
//             if (a[i] == current) {
//                 ++count;
//                 if (count == required) {
//                     current++;
//                     break;
//                 }
//                 current++;
//             }
//         }
        
//         cout << current << '\n';
//     }
    
//     return 0;
// }
