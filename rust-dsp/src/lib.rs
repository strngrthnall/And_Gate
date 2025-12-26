#[no_mangle]
pub extern "C" fn process_and_gate(input_a: f32, input_b: f32) -> f32 {
    // Definição de constantes de engenharia
    const GATE_HIGH: f32 = 10.0;
    const GATE_LOW: f32 = 0.0;
    const THRESHOLD: f32 = 0.1; // Schmitt Trigger simplificado para este exemplo

    // A Lógica AND real: Se A > 0.1V E B > 0.1V, então Saída = 10V
    if input_a > THRESHOLD && input_b > THRESHOLD {
        GATE_HIGH
    } else {
        GATE_LOW
    }
}