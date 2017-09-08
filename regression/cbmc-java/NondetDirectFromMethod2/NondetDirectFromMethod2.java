import org.cprover.CProver;

class NondetDirectFromMethod2
{
  int methodReturningInt()
  {
    return CProver.nondetWithoutNull();
  }

  void main()
  {
    int x = methodReturningInt();
    CProver.assume(x == 4);
    assert x == 4;
  }
}
