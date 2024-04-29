defmodule NifExample do
  @on_load :__on_load__

  def __on_load__ do
    path = :filename.join(:code.priv_dir(:nif_example), ~c"libnifexample")
    :erlang.load_nif(path, 0)
  end

  def upcase(_binary), do: :erlang.nif_error(:undef)
end
