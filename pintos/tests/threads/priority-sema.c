/* Tests that the highest-priority thread waiting on a semaphore
   is the first to wake up. */

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

static thread_func priority_sema_thread;
static struct semaphore sema;

void
test_priority_sema (void) 
{
  int i;
  
  /* This test does not work with the MLFQS. */
  ASSERT (!thread_mlfqs);

  sema_init (&sema, 0);
  thread_set_priority (PRI_MIN);
  for (i = 0; i < 10; i++) 
    {
<<<<<<< HEAD
      int priority = PRI_DEFAULT - (i + 3) % 10 - 1; // 21 ~ 30의 priority
=======
      int priority = PRI_DEFAULT - (i + 3) % 10 - 1;
>>>>>>> origin/JINHO
      char name[16];
      snprintf (name, sizeof name, "priority %d", priority);
      thread_create (name, priority, priority_sema_thread, NULL);
    }

  for (i = 0; i < 10; i++) 
    {
<<<<<<< HEAD
      sema_up (&sema); //10개의 티켓
=======
      sema_up (&sema);
>>>>>>> origin/JINHO
      msg ("Back in main thread."); 
    }
}

static void
priority_sema_thread (void *aux UNUSED) 
{
<<<<<<< HEAD
  sema_down (&sema); //티켓 사용
=======
  sema_down (&sema);
>>>>>>> origin/JINHO
  msg ("Thread %s woke up.", thread_name ());
}
