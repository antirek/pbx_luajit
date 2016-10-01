#ifndef EXPORT_H_INCLUDED
#define EXPORT_H_INCLUDED

#ifdef BUILD_SINGLE

#define EXPORT_DEF		static
#define EXPORT_DECL		static
#define INLINE_DECL		static inline
#else /* BUILD_SINGLE */

#define EXPORT_DEF
#define EXPORT_DECL		extern
#define INLINE_DECL		static inline

#endif /* BUILD_SINGLE */

#endif // EXPORT_H_INCLUDED
