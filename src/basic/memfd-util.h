/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

int memfd_create_wrapper(const char *name, unsigned mode);

int memfd_new(const char *name);
#if 0 /// UNNEEDED by elogind
int memfd_new_and_map(const char *name, size_t sz, void **p);
#endif // 0
int memfd_new_and_seal(const char *name, const void *data, size_t sz);

int memfd_add_seals(int fd, unsigned int seals);
#if 0 /// UNNEEDED by elogind
int memfd_get_seals(int fd, unsigned int *ret_seals);
int memfd_map(int fd, uint64_t offset, size_t size, void **p);
#endif // 0

int memfd_set_sealed(int fd);
#if 0 /// UNNEEDED by elogind
int memfd_get_sealed(int fd);
#endif // 0

int memfd_get_size(int fd, uint64_t *sz);
int memfd_set_size(int fd, uint64_t sz);
