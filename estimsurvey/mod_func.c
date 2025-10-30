#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _AXNODE_reg();
extern void _fh_reg();
extern void _fsquare_reg();
extern void _fzap_reg();
extern void _xstim_reg();
extern void _xtra_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," AXNODE.mod");
fprintf(stderr," fh.mod");
fprintf(stderr," fsquare.mod");
fprintf(stderr," fzap.mod");
fprintf(stderr," xstim.mod");
fprintf(stderr," xtra.mod");
fprintf(stderr, "\n");
    }
_AXNODE_reg();
_fh_reg();
_fsquare_reg();
_fzap_reg();
_xstim_reg();
_xtra_reg();
}
