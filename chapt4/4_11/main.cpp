#include "num_sequence.h"

int main()
{
    num_sequence ns;
    for(int i = 1; i <= num_sequence::num_of_sequence(); i++)
    {
        ns.set_sequence(num_sequence::nstype(i));
        int elem = ns.elem(8);
        ns.display(cout, ns, 8);
    }
}