# printf
## what is printf Algorithm
- what happens behind the hood? Printf starts to iterate or go through the format string,
it keeps a copy of each character in the string while it looks for a % symbol to know
if it’s dealing with a normal string or a formatted one. if it doesn’t find a % and a valid
format character, it prints whatever it has copied to standard output. but if it finds a
% ,it then checks to see what character lies next. If there’s no other character,
nothing is printed as mere % is treated as an invalid format specifier, BUT if there’s
some character, that’s where the real search and match case happens. One could
use a switch case, else..if but our approach will be an array of structures &
function pointers. why do we need one? cause a struct allows us to define a
variable that can hold multiple datatypes e.g types of additional variadic arguments:
char , int , float etc. The function pointer, which will be one of the struct member, would easily call on a conversion function if a match is found. now let’s get right into
