#include "include/gmmaintask.h"


gmMainTask::gmMainTask(int (*gridmd_main)(int, char *[]), int argc, char *argv[]):
    mFuncPtr(gridmd_main),
    mArgc(argc),
    mArgv(argv)
{;}

gmTask::gmTASK_TYPE gmMainTask::Type() const
{
    return gmTASK_GRIDMD_MAIN;
}

int gmMainTask::Run()
{
    return mFuncPtr(mArgc, mArgv);
}
