#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _AXNODE_reg(void);
extern void _fh_reg(void);
extern void _fsquare_reg(void);
extern void _fzap_reg(void);
extern void _xstim_reg(void);
extern void _xtra_reg(void);

void modl_reg(){
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
