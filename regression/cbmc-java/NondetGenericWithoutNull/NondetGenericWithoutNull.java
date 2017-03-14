import org.cprover.CProver;

class B { int a; }

class NondetGenericWithoutNull
{
  static void foo()
  {
    B b = CProver.nondetWithoutNull();
    assert b != null;
  }
}
