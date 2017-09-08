import org.cprover.CProver;

class test
{
  boolean methodReturningBoolean()
  {
    boolean b = CProver.nondetWithoutNull();
    return b;
  }

  void main()
  {
    boolean x = methodReturningBoolean();
    CProver.assume(x == true);
    assert x == true;
  }
}
