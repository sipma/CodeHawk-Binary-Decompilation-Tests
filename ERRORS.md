# Lifting Errors

Liftings are generated incrementally from the assembly code using analysis
results like invariants and reaching definitions provided by the OCaml
analyzer. During this process error conditions may be encountered that
prohibit a faithful lifting. When that happens an error log message is
generated that contains a brief description of the problem, and a diagnostic
code that indicates what party may be able to fix the problem, or whether
a construct was encountered that is simply not supported yet. The lifting
process is continued, and a lifting is produced, to enable better
investigation of the problem, but the lifting itself should be considered
invalid, whenever error messages were produced.

Error messages are tagged by a diagnostic category code. The following codes
are currently used:

- **USERDATA:** Data provided in the userdata is incorrect or incomplete.
     This should be able to be fixed by the user.
- **TYPING:** Type information provided via header files is incomplete or
    inconsistent. Many types are inferred automatically by the analyzer.
    However, a prerequisite for producing a lifting is the presence of a
    function prototype in a header file. In some cases it may also be necessary
    to provide types for local stack variables (via the function annotations).
    Type omissions should be fixable by the user. Type inconsistencies may
    be harder to diagnose, but are usually still fixable by the user.
- **UNSUPPORTED:** The lifting process hit a construct that is not yet
    supported by the analyzer, e.g., an indirect call, or an unsupported
    assembly instruction, or an unresolved branch condition. This problem is
    not fixable by the user; it requires the addition of new features to the
    analyzer.
- **INTERNAL:** An internal invariant was violated. The lifting process
    encountered an error value or is otherwise missing the required data
    to construct a valid lifting. This is generally not fixable by the user;
    it could be an analyzer defect that requires CodeHawk maintainers'
    attention.
