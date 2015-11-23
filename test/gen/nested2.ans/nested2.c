// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by zcm-gen

#include <string.h>
#include "nested2.h"

static int __nested2_hash_computed;
static uint64_t __nested2_hash;

uint64_t __nested2_hash_recursive(const __zcm_hash_ptr *p)
{
    const __zcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __nested2_get_hash)
            return 0;

    __zcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__nested2_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0xead96bf817b15699LL
         + __int8_t_hash_recursive(&cp)
         + __b_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __nested2_get_hash(void)
{
    if (!__nested2_hash_computed) {
        __nested2_hash = (int64_t)__nested2_hash_recursive(NULL);
        __nested2_hash_computed = 1;
    }

    return __nested2_hash;
}

int __nested2_encode_array(void *buf, int offset, int maxlen, const nested2 *p, int elements)
{
    int pos = 0, element;
    int thislen;

    for (element = 0; element < elements; element++) {

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].g), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        { int a;
        for (a = 0; a < p[element].g; a++) {
            thislen = __b_encode_array(buf, offset + pos, maxlen - pos, p[element].b_array[a], 5);
            if (thislen < 0) return thislen; else pos += thislen;
        }
        }

    }
    return pos;
}

int nested2_encode(void *buf, int offset, int maxlen, const nested2 *p)
{
    int pos = 0, thislen;
    int64_t hash = __nested2_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __nested2_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __nested2_encoded_array_size(const nested2 *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int8_t_encoded_array_size(&(p[element].g), 1);

        { int a;
        for (a = 0; a < p[element].g; a++) {
            size += __b_encoded_array_size(p[element].b_array[a], 5);
        }
        }

    }
    return size;
}

int nested2_encoded_size(const nested2 *p)
{
    return 8 + __nested2_encoded_array_size(p, 1);
}

int __nested2_decode_array(const void *buf, int offset, int maxlen, nested2 *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].g), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].b_array = (b**) zcm_malloc(sizeof(b*) * p[element].g);
        { int a;
        for (a = 0; a < p[element].g; a++) {
            p[element].b_array[a] = (b*) zcm_malloc(sizeof(b) * 5);
            thislen = __b_decode_array(buf, offset + pos, maxlen - pos, p[element].b_array[a], 5);
            if (thislen < 0) return thislen; else pos += thislen;
        }
        }

    }
    return pos;
}

int __nested2_decode_array_cleanup(nested2 *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int8_t_decode_array_cleanup(&(p[element].g), 1);

        { int a;
        for (a = 0; a < p[element].g; a++) {
            __b_decode_array_cleanup(p[element].b_array[a], 5);
            if (p[element].b_array[a]) free(p[element].b_array[a]);
        }
        }
        if (p[element].b_array) free(p[element].b_array);

    }
    return 0;
}

int nested2_decode(const void *buf, int offset, int maxlen, nested2 *p)
{
    int pos = 0, thislen;
    int64_t hash = __nested2_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __nested2_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int nested2_decode_cleanup(nested2 *p)
{
    return __nested2_decode_array_cleanup(p, 1);
}

int __nested2_clone_array(const nested2 *p, nested2 *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int8_t_clone_array(&(p[element].g), &(q[element].g), 1);

        q[element].b_array = (b**) zcm_malloc(sizeof(b*) * q[element].g);
        { int a;
        for (a = 0; a < p[element].g; a++) {
            q[element].b_array[a] = (b*) zcm_malloc(sizeof(b) * 5);
            __b_clone_array(p[element].b_array[a], q[element].b_array[a], 5);
        }
        }

    }
    return 0;
}

nested2 *nested2_copy(const nested2 *p)
{
    nested2 *q = (nested2*) malloc(sizeof(nested2));
    __nested2_clone_array(p, q, 1);
    return q;
}

void nested2_destroy(nested2 *p)
{
    __nested2_decode_array_cleanup(p, 1);
    free(p);
}

int nested2_publish(zcm_t *lc, const char *channel, const nested2 *p)
{
      int max_data_size = nested2_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = nested2_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = zcm_publish (lc, channel, (char *)buf, (size_t)data_size);
      free (buf);
      return status;
}

struct _nested2_subscription_t {
    nested2_handler_t user_handler;
    void *userdata;
    zcm_sub_t *z_sub;
};
static
void nested2_handler_stub (const zcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    nested2 p;
    memset(&p, 0, sizeof(nested2));
    status = nested2_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding nested2!!!\n", status);
        return;
    }

    nested2_subscription_t *h = (nested2_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    nested2_decode_cleanup (&p);
}

nested2_subscription_t* nested2_subscribe (zcm_t *zcm,
                    const char *channel,
                    nested2_handler_t f, void *userdata)
{
    nested2_subscription_t *n = (nested2_subscription_t*)
                       malloc(sizeof(nested2_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->z_sub = zcm_subscribe (zcm, channel,
                              nested2_handler_stub, n);
    if (n->z_sub == NULL) {
        fprintf (stderr,"couldn't reg nested2 ZCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int nested2_unsubscribe(zcm_t *zcm, nested2_subscription_t* hid)
{
    int status = zcm_unsubscribe (zcm, hid->z_sub);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe nested2_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

