import org.cprover.CProver;

class NondetArray
{
  void foo()
  {
    Object[] obj = CProver.nondetWithoutNull();
    assert obj != null;
  }
}
