/* Local Linux 3.4 compatibility for the Android 3.18 Binder donor. */
#ifndef _BINDER_COMPAT34_H
#define _BINDER_COMPAT34_H
static inline int binder34_map_vm_area(struct vm_struct *area, pgprot_t prot,
                                      struct page **pages)
{
 return map_vm_area(area, prot, &pages);
}
#define BINDER_MAX_NICE 19
#define BINDER_SIZE_MAX ((size_t)-1)
#define binder34_page_aligned(addr) IS_ALIGNED((unsigned long)(addr), PAGE_SIZE)
static inline long binder34_rlimit_to_nice(unsigned long rlim)
{
 return BINDER_MAX_NICE - (long)rlim + 1;
}
/* Matches Android common 3.4 exclusive freezer-aware waiting. */
#define binder34_wait_event_freezable_exclusive(wq, condition) \
 ({ int _ret; freezer_do_not_count(); \
    _ret = wait_event_interruptible_exclusive(wq, condition); \
    freezer_count(); _ret; })

#define binder_hlist_entry_safe(ptr, type, member) \
 ({ typeof(ptr) _p = (ptr); _p ? hlist_entry(_p, type, member) : NULL; })
#define binder_hlist_for_each_entry(pos, head, member) \
 for (pos = binder_hlist_entry_safe((head)->first, typeof(*(pos)), member); \
      pos; \
      pos = binder_hlist_entry_safe((pos)->member.next, typeof(*(pos)), member))
#define binder_hlist_for_each_entry_safe(pos, n, head, member) \
 for (pos = binder_hlist_entry_safe((head)->first, typeof(*(pos)), member); \
      pos && ({ n = (pos)->member.next; 1; }); \
      pos = binder_hlist_entry_safe(n, typeof(*(pos)), member))
#endif
