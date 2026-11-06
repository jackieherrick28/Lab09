# Lab09
# By: Jackie Herrick
# Date: 11/05/26
  # a. These programs go through the basic system calls on a Portable Operating System Interface (POSIX) operating system. 
    # info: Information maintenance system calls provide data concerning the entire running system.
    # pinfo: The system calls available for retrieving information about processes in the system. 
    # pmod: Modifies its own priority to REDUCE it by 10
    # finfo: Displays file information about a given file  provided via the command line.
  # b. How to build the program
    # info 
      # clock_gettime: retrieve the current time in seconds
      # uname: display system information such as kernel name, version, release, machine hardware, and operating system
      # gethostname: retrieves the standard hostname of the local machine.
      # get_nprocs: retrieves the number of processors available on the system.
      # sysconf: retrieves system configuration information.
      # getpagesize: Returns the system memory page size.
    # pinfo
      # getpid: Retrieves the process ID.
      # getpriority:  Retrieves the group ID.
      # sched_getscheduler: Retrieves the scheduling policy of the process.
      # getcpu: Pointer to an integer that receives the current CPU number.
      # getrusage: Retrieves detailed resource‑usage statistics—such as user CPU time, system CPU time, memory usage, page       # faults, and context switches—for a process, its children, or a single thread.
      # getrlimit: retrieves a process’s soft and hard resource limits 
    # pmod
    
    # finfo
  # c. How to run the program – available command-line options
