# 🦀 Rusted Modules - AND Gate

![VCV Rack](https://img.shields.io/badge/VCV%20Rack-2.0-blue?style=flat-square&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA4AAAAOCAYAAAAfSC3RAAAACXBIWXMAAAsTAAALEwEAmpwYAAAA)
![Rust](https://img.shields.io/badge/Rust-FFI-orange?style=flat-square&logo=rust)
![C++](https://img.shields.io/badge/C++-17-00599C?style=flat-square&logo=cplusplus)
![License](https://img.shields.io/badge/License-CC0-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow?style=flat-square)

Um módulo de porta lógica AND para **VCV Rack 2.0** com processamento de sinal em **Rust** via FFI (Foreign Function Interface).

## 📖 Sobre o Projeto

Este projeto é uma prova de conceito que demonstra a integração entre **Rust** e **C++** no ecossistema VCV Rack. O núcleo do processamento de sinal digital (DSP) é implementado em Rust, enquanto a interface com o VCV Rack é feita em C++.

### Por que Rust + VCV Rack?

- 🔒 **Segurança de memória** garantida pelo compilador
- ⚡ **Performance** comparável ao C/C++
- 🧪 **Facilidade de testes** para algoritmos DSP
- 📦 **Ecossistema Cargo** para gerenciamento de dependências

## 🎛️ Módulos

### AND Gate

Uma porta lógica AND simples com duas entradas e uma saída.

| Entrada | Descrição |
|---------|-----------|
| **A** | Entrada de gate A |
| **B** | Entrada de gate B |

| Saída | Descrição |
|-------|-----------|
| **OUT** | 10V se A > 0.1V **E** B > 0.1V, caso contrário 0V |

## 🛠️ Compilação

### Pré-requisitos

- [VCV Rack SDK 2.0+](https://vcvrack.com/manual/Building)
- [Rust](https://rustup.rs/) (stable)
- Compilador C++ com suporte a C++17

### Build

```bash
# Compilar a biblioteca Rust
cd rust-dsp
cargo build --release

# Compilar o plugin VCV Rack
cd ..
make
```

## 📁 Estrutura do Projeto

```
And_Gate/
├── rust-dsp/           # Biblioteca Rust com DSP
│   ├── Cargo.toml
│   └── src/
│       └── lib.rs      # Lógica AND implementada em Rust
├── src/
│   ├── MyModule.cpp    # Widget e Module do VCV Rack
│   ├── plugin.cpp      # Registro do plugin
│   └── plugin.hpp      # Headers
├── res/
│   └── AndGate.svg     # Painel do módulo
├── plugin.json         # Metadados do plugin
└── Makefile
```

## 🗺️ Roadmap

### ✅ Concluído

- [x] Estrutura básica do projeto
- [x] Integração Rust ↔ C++ via FFI
- [x] Implementação da lógica AND
- [x] Compilação funcional do plugin

### 🚧 Em Progresso

- [ ] **Melhorar aparência do SVG** - O painel atual é básico e precisa de um design mais profissional
- [ ] Adicionar LEDs indicadores de estado nas entradas e saída

### 📋 Planejado

- [ ] **Novos módulos lógicos**
  - [ ] OR Gate
  - [ ] XOR Gate
  - [ ] NOT Gate
  - [ ] NAND Gate
  - [ ] NOR Gate
- [ ] **Funcionalidades avançadas**
  - [ ] Schmitt Trigger configurável via knob
  - [ ] Hysteresis ajustável
  - [ ] Modo de operação analógico (soft clipping)
- [ ] **Qualidade**
  - [ ] Testes unitários para o código Rust
  - [ ] CI/CD para builds automatizados
  - [ ] Documentação completa da API
- [ ] **Distribuição**
  - [ ] Publicar na VCV Library

## 🤝 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para:

- 🐛 Reportar bugs
- 💡 Sugerir novas features
- 🎨 Melhorar o design dos painéis SVG
- 📝 Melhorar a documentação

## 📄 Licença

Este projeto está licenciado sob **CC0** - veja o arquivo [LICENSE](LICENSE) para detalhes.

## 👤 Autor

**Marcos Vinicius Ribeiro de Miranda**

---

<p align="center">
  Feito com 🦀 Rust + ❤️ para a comunidade VCV Rack
</p>
