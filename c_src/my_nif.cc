#include "my_nif.h"

ERL_NIF_TERM upcase(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if (argc != 1) {
    return enif_make_tuple2(env, enif_make_atom(env, "error"), enif_make_atom(env, "invalid_arg_count"));
  }

  ErlNifBinary bin;
  if (!enif_inspect_binary(env, argv[0], &bin)) {
    return enif_make_tuple2(env, enif_make_atom(env, "error"), enif_make_atom(env, "invalid_argument"));
  }

  ErlNifBinary out_bin;
  // enif_alloc_binary(bin.size, &out_bin);

  for (int i = 0; i < bin.size; i++) {
    char c = bin.data[i];
    if (c >= 'a' && c <= 'z') {
      out_bin.data[i] = c - 'a' + 'A';
    } else {
      out_bin.data[i] = c;
    }
  }

  return enif_make_tuple2(env, enif_make_atom(env, "ok"), enif_make_binary(env, &out_bin));
}

static int load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info) {
  return 0;
}

static ErlNifFunc nif_funcs[] = {
    {"upcase", 1, upcase}};

ERL_NIF_INIT(Elixir.NifExample, nif_funcs, &load, NULL, NULL, NULL);