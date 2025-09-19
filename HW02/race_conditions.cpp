# include < iostream >
# include < thread >
# include < vector >
# include < mutex >
# include < atomic >
# include < chrono >
constexpr int ITER = 1 0 0 0 0 0 ;
void inc_no_lock ( int & counter ) {
for ( int i = 0 ; i < ITER ; ++ i ) counter ++; // data race !
}
void inc_with_mutex ( int & counter , std :: mutex & m ) {
for ( int i = 0 ; i < ITER ; ++ i ) {
std :: lock_guard < std :: mutex > lk ( m ) ;
++ counter ;
}
}
void inc_atomic ( std :: atomic < int > & counter ) {
for ( int i = 0 ; i < ITER ; ++ i ) counter . fetch_add ( 1 , std ::
m e m o r y _ o r d e r _ r e l a x e d ) ;
}
template < typename F >
int run_and_time ( int T , F && fn ) {
auto t 0 = std :: chrono :: h i g h _ r e s o l u t i o n _ c l o c k :: now () ;
std :: vector < std :: thread > ths ;
ths . reserve ( T ) ;
for ( int i = 0 ; i < T ; ++ i ) ths . emplace_back ( fn ) ;
for ( auto & t : ths ) t . join () ;
auto t 1 = std :: chrono :: h i g h _ r e s o l u t i o n _ c l o c k :: now () ;
return std :: chrono :: duration < double , std :: milli >( t 1 - t 0 ) . count () ;
}
int main () {
const int T = std :: thread :: h a r d w a r e _ c o n c u r r e n c y () ?
std :: thread :: h a r d w a r e _ c o n c u r r e n c y () : 4 ;
const int expected = T * ITER ;
int counter = 0 ;
auto ms = run_and_time (T , [&]{ inc_no_lock ( counter ) ; }) ;
std :: cout << " [ No lock ] counter = " << counter
<< " ( expected " << expected << " ) , "
<< ms << " ms \ n " ;
}
{ // Mutex
int counter = 0 ;
std :: mutex m ;
auto ms = run_and_time (T , [&]{ inc_with_mutex ( counter , m ) ; }) ;
std :: cout << " [ Mutex ] counter = " << counter
<< " ( expected " << expected << " ) , "
<< ms << " ms \ n " ;
}
{ // Atomic
std :: atomic < int > counter { 0 };
auto ms = run_and_time (T , [&]{ inc_atomic ( counter ) ; }) ;
std :: cout << " [ Atomic ] counter = " << counter . load ()
<< " ( expected " << expected << " ) , "
<< ms << " ms \ n " ;
}
return 0 ;
}
{ // No lock ( incorrect )
