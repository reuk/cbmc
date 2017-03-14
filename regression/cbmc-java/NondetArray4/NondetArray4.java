import org.cprover.CProver;

class NondetArray4
{
  void foo()
  {
    int a = 1;
    int b = 2;
    int c = 3;

    Integer[] ints = CProver.nondetWithoutNull();
    assert ints != null;
  }
}
